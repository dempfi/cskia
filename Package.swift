// swift-tools-version: 5.9

import PackageDescription

let version = "m145-fba326b"
let checksums: [String: String] = [
  "skia": "d139d3c81443071414546f7e2e4019810ae29fbac43a8c5fd44cab6f6850f2a6",
  "skparagraph": "2825fbbc792928a8baf8ae4c1a554bf1d3bc203c3c59ef6548a7c481f4d614ed",
  "skshaper": "d0576908494ad8df9cddccf982754e8b25d5d4981ebacdd263e302c922ab4bc0",
  "skunicode": "5f265bfb34ef66335a811f964961d3c8f6bf445f6c67df1a5724d5574c698fd7",
]

let repo = "https://github.com/dempfi/cskia"

let package = Package(
  name: "cskia",
  platforms: [
    .macOS(.v13),
    .iOS(.v15),
    .tvOS(.v15),
  ],
  products: [
    .library(name: "cskia", targets: ["cskia"]),
  ],
  targets: [
    .target(
      name: "cskia",
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
