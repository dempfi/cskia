// swift-tools-version: 5.9

import PackageDescription

let version = "m145-fba326b"
let checksums: [String: String] = [
  "skia": "6631b72ff2131908645a9bce43726f5e768bd21b4eb043bcf74527ae30c9361c",
  "skparagraph": "9f23676e3e807806f8cf1718be62b57fd1716192d971c785c1ec5b739845448f",
  "skshaper": "a095c63f2bab57150c4ef19951474eceb52ed1e8e65f922b9310edd617b2b3e2",
  "skunicode": "68d7b3ad1d16997663449346b18d8e0c0c201908d10923a13ed833c9de64056f",
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
