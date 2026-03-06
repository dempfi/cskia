// swift-tools-version: 5.9

import PackageDescription

let version = "m145-fba326b-2"
let checksums: [String: String] = [
  "skia": "95b43948d3bc2bce45d6f3d94a6dedb3b922a522a4754421ccbfce6b35e627c1",
  "skparagraph": "87162d599bd2fe963af386845ce822ef8a4d825a77d1e9b0a9080fd90f1dbe56",
  "skshaper": "4801b4034bf45d12d5837c5bfd7a21d7dfffbae7520f2b9ce603d4ccfdb1594f",
  "skunicode": "7933bba7b3bdbcf4cdd683c07faae45b1f19f8dee8709eb829063be63a39d923",
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
