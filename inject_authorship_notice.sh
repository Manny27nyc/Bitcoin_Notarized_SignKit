#!/bin/bash
# 🔐 inject_authorship_notice.sh
# Verified authorship header injector — Manuel J. Nieves (B4EC 7343)

echo "🔍 Scanning all PHP files for missing authorship headers..."

find . -type f -name "*.php" | while read -r file; do
  if ! grep -q "Verified Authorship Notice" "$file"; then
    cat ~/authorship_header.php "$file" > "${file}.tmp" && mv "${file}.tmp" "$file"
    echo "✅ Injected: $file"
  else
    echo "⚠️ Already contains header: $file"
  fi
done

echo "✅ Authorship injection completed."
