// swift-tools-version: 5.9

import PackageDescription

let version = "m145-fba326b"
let checksums: [String: String] = [
  "skia": "de142dbff0fdeacac0b56b992d1f12a069db48c1cddc199e3982d5c3f43968f5",
  "skparagraph": "eb53ea31f399d50954ab253f454609e7359ad18ce87321d604e47a5c6b4ccc56",
  "skshaper": "bb35a888e874fa997e3e27926c29032d872867c4e1f34fb1d34e847d13eea9f1",
  "skunicode": "43990581d45ffcbb343082bb8f07801e02a2304525f579aba22c028623209876",
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
