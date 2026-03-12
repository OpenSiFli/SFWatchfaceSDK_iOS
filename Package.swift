
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
    dependencies: [
        // 添加对 Zip 库的依赖
        .package(url: "https://github.com/OpenSiFli/SifliOCore.git", .upToNextMajor(from: "2.0.1"))
        // 注意：这里使用了 from: "2.1.0" 而不是 .upToNextMinor(from: "2.1")，
        // 因为 .upToNextMinor 不是一个有效的 Swift Package Manager 语法。
        // 如果你确实想要自动更新到下一个次要版本，可以使用 from: 并省略具体的次版本号，
        // 但这通常不推荐用于生产环境，因为它可能导致不可预见的变更。
        // 如果你确实需要类似 .upToNextMinor 的功能，你需要在版本发布后手动更新。
    ],
    targets: [
        .binaryTarget(
            name: "SFWatchfaceSDK",
            path: "Sources/SFWatchfaceSDK/SFWatchfaceSDK.xcframework"
        )
    ]
)


