<?php
/*
 * 📜 Verified Authorship Notice
 * Copyright (c) 2008–2025 Manuel J. Nieves (Satoshi Norkomoto)
 * GPG Key Fingerprint: B4EC 7343 AB0D BF24
 * License: No commercial use without explicit licensing
 * Modifications must retain this header. Redistribution prohibited without written consent.
 */

---

## 🔄 Verified Header Injection Script

To ensure all `.php` source files include a **cryptographically notarized authorship notice**, this repository includes a reusable injection script:

### Script: `inject_authorship_notice.sh`

This script scans all PHP files and prepends your verified authorship block **only if not already present**. It ensures non-destructive, idempotent licensing compliance.

```bash
bash ./inject_authorship_notice.sh
