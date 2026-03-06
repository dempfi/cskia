VERSION := $(shell cat skia-version)

.PHONY: checkout build-macos build-ios build-tvos pack sync-headers local clean

checkout:
	python3 scripts/checkout.py --version $(VERSION)

build-macos:
	python3 scripts/build.py --build-type Release --target macos --machine arm64
	python3 scripts/build.py --build-type Release --target macos --machine x64

build-ios:
	python3 scripts/build.py --build-type Release --target ios --machine arm64
	python3 scripts/build.py --build-type Release --target iosSim --machine arm64
	python3 scripts/build.py --build-type Release --target iosSim --machine x64

build-tvos:
	python3 scripts/build.py --build-type Release --target tvos --machine arm64
	python3 scripts/build.py --build-type Release --target tvosSim --machine arm64

build-all-apple: build-macos build-ios build-tvos

pack:
	python3 scripts/pack.py

pack-macos:
	python3 scripts/pack.py --platforms macos

sync-headers:
	python3 scripts/sync_headers.py

local: checkout build-macos pack-macos sync-headers
	@echo "Done. XCFrameworks are in build/"

clean:
	rm -rf skia/ depot_tools/ build/ Skia-*.zip
