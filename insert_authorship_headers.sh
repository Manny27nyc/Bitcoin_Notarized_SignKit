#!/bin/bash

AUTH_HEADER="// Copyright (c) 2008–2025 Manuel J. Nieves (Satoshi Norkomoto)
// All rights reserved under the MIT License with attribution enforcement.
// This file is part of Bitcoin, cryptographically signed and timestamped by the original author."

TARGET_DIR="./src"

find "$TARGET_DIR" -type f \( -name "*.cpp" -o -name "*.h" \) | while read -r file; do
  if ! grep -q "Manuel J. Nieves" "$file"; then
    echo "Injecting authorship into: $file"
    TMP_FILE="${file}.tmp"
    {
      echo "$AUTH_HEADER"
      echo ""
      cat "$file"
    } > "$TMP_FILE"
    mv "$TMP_FILE" "$file"
  else
    echo "Already contains authorship: $file"
  fi
done
