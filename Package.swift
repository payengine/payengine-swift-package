// swift-tools-version: 5.5
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "PayEnginePackage",
    platforms: [
        .iOS(.v15)
    ],
    products: [
        
        // Products define the executables and libraries a package produces, making them visible to other packages.
        .library(
            name: "PayEnginePackage",
            targets: ["PayEnginePackage", "PayEngineSDK"]),
    ],
    targets: [
        .binaryTarget(name: "PayEngineSDK", path: "./Frameworks/PayEngineSDK.xcframework"),
        // Targets are the basic building blocks of a package, defining a module or a test suite.
        // Targets can depend on other targets in this package and products from dependencies.
        .target(
            name: "PayEnginePackage",
            dependencies: [
                "PEDevicePaymentSDK",
            ]),

    ]
)