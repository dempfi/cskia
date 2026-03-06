#! /usr/bin/env python3
"""
Sync C API headers from api/include/ to Sources/cskia/include/.
Preserves module.modulemap and umbrella.h (which are CSkia-specific).
"""

import os, shutil, sys

REPO_ROOT = os.path.join(os.path.dirname(__file__), os.pardir)

def main():
  src = os.path.join(REPO_ROOT, 'api', 'include')
  dst = os.path.join(REPO_ROOT, 'Sources', 'cskia', 'include')

  preserve = {'module.modulemap', 'umbrella.h'}

  # Remove old headers (except preserved files)
  for f in os.listdir(dst):
    if f in preserve:
      continue
    path = os.path.join(dst, f)
    if os.path.isfile(path) and f.endswith('.h'):
      os.remove(path)

  # Copy fresh headers
  copied = 0
  for f in os.listdir(src):
    if f.endswith('.h'):
      shutil.copy2(os.path.join(src, f), os.path.join(dst, f))
      copied += 1

  print(f'> Synced {copied} headers from api/include/ to Sources/cskia/include/')
  return 0

if __name__ == '__main__':
  sys.exit(main())
