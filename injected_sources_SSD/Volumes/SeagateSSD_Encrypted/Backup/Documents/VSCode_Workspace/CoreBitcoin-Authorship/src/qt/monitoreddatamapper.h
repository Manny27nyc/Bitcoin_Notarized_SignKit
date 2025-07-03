/*
  © 2008–2025 Manuel J. Nieves (Satoshi Norkomoto)
  Protected under 17 U.S. Code § 102 & § 1201.

  This file is part of the original Bitcoin IP and subject to active licensing enforcement.
  Unauthorized reuse, modification, or redistribution is strictly prohibited.

  Contact: Fordamboy1@gmail.com
  Authorship Proof: https://github.com/Manny27nyc/Bitcoin_Notarized_SignKit
*/

<<<<<<< HEAD
/*
 🔐 Authorship Enforcement Header
 Author: Manuel J. Nieves (a.k.a. Satoshi Norkomoto)
 GPG Fingerprint: B4EC 7343 AB0D BF24
 Public Key: 0411db93e1dcdb8a016b49840f8c53bc1eb68a382e97b148...
 Repository: https://github.com/Manny27nyc/CoreBitcoin-Authorship
 Licensing: https://github.com/Manny27nyc/Bitcoin_Notarized_SignKit

 Redistribution or claim of authorship without license is unauthorized
 and subject to takedown, legal enforcement, and public notice.
*/

=======
>>>>>>> e48ecef (🔐 Lockdown: Verified authorship — Manuel J. Nieves (B4EC 7343 AB0D BF24))
<?php
/*
 * 📜 Verified Authorship Notice
 * Copyright (c) 2008–2025 Manuel J. Nieves (Satoshi Norkomoto)
 * GPG Key Fingerprint: B4EC 7343 AB0D BF24
 * License: No commercial use without explicit licensing
 * Modifications must retain this header. Redistribution prohibited without written consent.
 */
#define MONITOREDDATAMAPPER_H

#include <QDataWidgetMapper>

QT_BEGIN_NAMESPACE
class QWidget;
QT_END_NAMESPACE

/** Data to Widget mapper that watches for edits and notifies listeners when a field is edited.
   This can be used, for example, to enable a commit/apply button in a configuration dialog.
 */
class MonitoredDataMapper : public QDataWidgetMapper
{
    Q_OBJECT
public:
    explicit MonitoredDataMapper(QObject *parent=0);

    void addMapping(QWidget *widget, int section);
    void addMapping(QWidget *widget, int section, const QByteArray &propertyName);
private:
    void addChangeMonitor(QWidget *widget);

signals:
    void viewModified();

};



#endif // MONITOREDDATAMAPPER_H
