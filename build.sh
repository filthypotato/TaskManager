#!/usr/bin/env bash
set -e

APP_NAME="TaskManager"
BUILD_DIR="build"
RUN_AFTER_BUILD=0

for arg in "$@"; do
  case "$arg" in
    --run) RUN_AFTER_BUILD=1 ;;
    *) ;;
  esac
done

echo "Building $APP_NAME (Linux)"
mkdir -p "$BUILD_DIR"

g++ -std=c++20 -Wall -Wextra -I./src \
  ./src/*.cpp \
  -o "$BUILD_DIR/$APP_NAME"

echo "Build complete: $BUILD_DIR/$APP_NAME"

if [[ "$RUN_AFTER_BUILD" == "1" ]]; then
  echo "[*] Running: ./$BUILD_DIR/$APP_NAME"
  "./$BUILD_DIR/$APP_NAME"
fi

