// swift-tools-version: 5.9

import PackageDescription

let version = "m145-fba326b"
let checksums: [String: String] = [
  "skia": "e9c3abadf2367101f1a480e2723367239ade84006f50b57d34beef004abf2832",
  "skparagraph": "05019bfc75c9cdd97f621f354dac2e042e213f6858d32cf5fb05044fd44ab225",
  "skshaper": "09ca3b981b9e53e0d8d886f71bf9a994174b87573813f330d4d2580245bddc51",
  "skunicode": "146f394327e9cd7e6d3c2c146c3308bae5e1cdeec0eba55cfe5d190c55e0b980",
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
