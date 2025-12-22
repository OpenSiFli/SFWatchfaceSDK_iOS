
// swift-tools-version: 6.0
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "SFWatchfaceSDK",
    platforms: [
        .iOS(.v12),
        .macOS(.v10_15)
    ],
    products: [
        .library(
            name: "SFWatchfaceSDK",
            targets: ["SFWatchfaceSDK"]),
    ],

    targets: [
        .binaryTarget(
            name: "SFWatchfaceSDK",
            path: "Sources/SFWatchfaceSDK/SFWatchfaceSDK.xcframework"
        )
    ]
)


