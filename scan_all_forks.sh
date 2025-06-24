#!/bin/bash

mkdir -p forks
mkdir -p MyNotarizedReference

# Load your reference hashes (make sure these files are already in MyNotarizedReference)
find ./MyNotarizedReference -type f -exec sha256sum {} \; > reference_hashes.txt

# Forks to check
for url in \
  https://github.com/eddyCais/CoreBitcoin.git \
  https://github.com/tdmllc1/CoreBitcoin.git \
  https://github.com/jiuxikeji/CoreBitcoin.git \
  https://github.com/LinberDuan/CoreBitcoin.git \
  https://github.com/Hioln/CoreBitcoin.git \
  https://github.com/DiwakarThapa/CoreBitcoin.git \
  https://github.com/ruyizi/CoreBitcoin.git \
  https://github.com/tdmllc/CoreBitcoin.git \
  https://github.com/BaHui/CoreBitcoin.git \
  https://github.com/lili-shangshu/CoreBitcoin.git \
  https://github.com/asicminer001/CoreBitcoin.git \
  https://github.com/gavin-tang/CoreBitcoin.git \
  https://github.com/dong4255/CoreBitcoin.git \
  https://github.com/xiaowei772028339/CoreBitcoin.git \
  https://github.com/kufufu9/CoreBitcoin.git \
  https://github.com/dindinw/CoreBitcoin.git \
  https://github.com/fengmingdev/CoreBitcoin.git \
  https://github.com/Jeongjaegu/CoreBitcoin.git \
  https://github.com/Mylittleswift/CoreBitcoin.git \
  https://github.com/FinLaas/CoreBitcoin.git \
  https://github.com/NeoTim/CoreBitcoin.git \
  https://github.com/liunina/CoreBitcoin.git \
  https://github.com/mkll/CoreBitcoin.git \
  https://github.com/zdmob/CoreBitcoin.git
do
  dir="forks/$(basename "$url" .git)"
  echo "🔍 Scanning $url → $dir"
  git clone --depth=1 "$url" "$dir" || { echo "❌ Failed to clone $url"; continue; }

  find "$dir" -type f -exec sha256sum {} \; > "${dir}_hashes.txt"
  comm -12 <(sort reference_hashes.txt) <(sort "${dir}_hashes.txt") > "${dir}_matches.txt"

  if [[ -s "${dir}_matches.txt" ]]; then
    echo "⚠️ MATCHES FOUND in $dir:"
    cat "${dir}_matches.txt"
  else
    echo "✅ CLEAN: No matches in $dir"
  fi
done
