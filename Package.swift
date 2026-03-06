// swift-tools-version: 5.9

import PackageDescription

// Updated by CI on each release. To use local XCFrameworks instead,
// change binaryTarget entries to use `path:` instead of `url:`.
let version = "m119-89907a0"
let checksums: [String: String] = [
  "skia": "PLACEHOLDER",
  "skparagraph": "PLACEHOLDER",
  "skshaper": "PLACEHOLDER",
  "skunicode": "PLACEHOLDER",
]

let repo = "https://github.com/dempfi/skia"

let package = Package(
  name: "Skia",
  platforms: [
    .macOS(.v13),
    .iOS(.v15),
    .tvOS(.v15),
  ],
  products: [
    .library(name: "Skia", targets: ["Skia"]),
  ],
  targets: [
    .target(
      name: "Skia",
      dependencies: ["CSkia"]
    ),
    .testTarget(
      name: "SkiaTests",
      dependencies: ["Skia"]
    ),
    .target(
      name: "CSkia",
      dependencies: ["SkiaBinary", "SkParagraphBinary", "SkShaperBinary", "SkUnicodeBinary"],
      cSettings: [
        .headerSearchPath("include"),
      ]
    ),
    .binaryTarget(
      name: "SkiaBinary",
      url: "\(repo)/releases/download/\(version)/skia-macos.xcframework.zip",
      checksum: checksums["skia"]!
    ),
    .binaryTarget(
      name: "SkParagraphBinary",
      url: "\(repo)/releases/download/\(version)/skparagraph-macos.xcframework.zip",
      checksum: checksums["skparagraph"]!
    ),
    .binaryTarget(
      name: "SkShaperBinary",
      url: "\(repo)/releases/download/\(version)/skshaper-macos.xcframework.zip",
      checksum: checksums["skshaper"]!
    ),
    .binaryTarget(
      name: "SkUnicodeBinary",
      url: "\(repo)/releases/download/\(version)/skunicode-macos.xcframework.zip",
      checksum: checksums["skunicode"]!
    ),
  ]
)
