#! /usr/bin/env python3

import argparse, base64, os, platform, re, subprocess

REPO_ROOT = os.path.join(os.path.dirname(__file__), os.pardir)

def create_parser(version_required=False):
  parser = argparse.ArgumentParser()
  parser.add_argument('--build-type', default='Release')
  parser.add_argument('--version', required=version_required)
  parser.add_argument('--classifier')
  parser.add_argument('--host')
  parser.add_argument('--machine')
  parser.add_argument('--ndk')
  parser.add_argument('--target')
  return parser

def host():
  parser = create_parser()
  (args, _) = parser.parse_known_args()
  return args.host if args.host else {'Darwin': 'macos', 'Linux': 'linux', 'Windows': 'windows'}[platform.system()]

def host_machine():
  return {'AMD64': 'x64', 'x86_64': 'x64', 'arm64': 'arm64', 'aarch64': 'arm64'}[platform.machine()]

def machine():
  parser = create_parser()
  (args, _) = parser.parse_known_args()
  return args.machine if args.machine else host_machine()

def target():
  parser = create_parser()
  (args, _) = parser.parse_known_args()
  return args.target if args.target else host()

def version():
  parser = create_parser()
  (args, _) = parser.parse_known_args()

  if args.version:
    return args.version

  version_file = os.path.join(REPO_ROOT, 'skia-version')
  if os.path.exists(version_file):
    with open(version_file) as f:
      return f.read().strip()

  raise RuntimeError('No --version specified and no skia-version file found')

def build_type():
  parser = create_parser()
  (args, _) = parser.parse_known_args()
  return args.build_type

def classifier():
  parser = create_parser()
  (args, _) = parser.parse_known_args()
  return '-' + args.classifier if args.classifier else ''

def github_headers():
  if os.environ.get('GITHUB_BASIC'):
    auth = 'Basic ' + base64.b64encode(os.environ.get('GITHUB_BASIC').encode('utf-8')).decode('utf-8')
  else:
    auth = 'token ' + os.environ.get('GITHUB_TOKEN')
  return {
    'Accept': 'application/vnd.github.v3+json',
    'Authorization': auth
  }

def ndk():
  parser = create_parser()
  (args, _) = parser.parse_known_args()
  return args.ndk if args.ndk else ''

def github_repo():
  return os.environ.get('GITHUB_REPOSITORY', 'dempfi/skia')
