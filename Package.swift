// swift-tools-version: 5.9

import PackageDescription

let version = "m145-fba326b-1"
let checksums: [String: String] = [
  "skia": "0ae06d52f346c6f8e9bf4e07a42d2a93821d68880020c1aa30506440bc166df6",
  "skparagraph": "ffe56e8f1799fb3da7cce27ad8f575206af87ea01e2d5d9369d1a61c2be0a1fc",
  "skshaper": "efbabbd35a7ce2f45f5c62749bfa68c6076b8491e13a938c91b225edc08df0b7",
  "skunicode": "ce158f03588ade82a8a34094fd5bcdee1e203014ab3c08882a64011c53d91ab5",
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
