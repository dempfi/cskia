#! /usr/bin/env python3

import common, json, os, re, sys, urllib.request

def main():
  version = common.version()
  build_type = common.build_type()
  machine = common.machine()
  target = common.target()
  classifier = common.classifier()
  repo = common.github_repo()

  zip = 'Skia-' + version + '-' + target + '-' + build_type + '-' + machine + classifier + '.zip'
  zip_path = os.path.join(common.REPO_ROOT, zip)
  if not os.path.exists(zip_path):
    print("Can't find \"" + zip + '"')
    return 1

  headers = common.github_headers()

  try:
    url = f'https://api.github.com/repos/{repo}/releases/tags/{version}'
    resp = urllib.request.urlopen(urllib.request.Request(url, headers=headers)).read()
  except urllib.error.URLError:
    data = json.dumps({'tag_name': version, 'name': version}).encode('utf-8')
    url = f'https://api.github.com/repos/{repo}/releases'
    req = urllib.request.Request(url, data=data, headers={**headers, 'Content-Type': 'application/json'})
    resp = urllib.request.urlopen(req).read()

  upload_url = re.match(r'https://.*/assets', json.loads(resp.decode('utf-8'))['upload_url']).group(0)

  print('Uploading', zip, 'to', upload_url)
  headers['Content-Type'] = 'application/zip'
  headers['Content-Length'] = str(os.path.getsize(zip_path))
  with open(zip_path, 'rb') as data:
    urllib.request.urlopen(urllib.request.Request(upload_url + '?name=' + zip, data=data, headers=headers))

  return 0

if __name__ == '__main__':
  sys.exit(main())
