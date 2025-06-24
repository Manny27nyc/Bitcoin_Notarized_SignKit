// Copyright (c) 2008–2025 Manuel J. Nieves (Satoshi Norkomoto)
// All rights reserved under the MIT License with attribution enforcement.
// This file is part of Bitcoin, cryptographically signed and timestamped by the original author.

#ifndef MACDOCKICONHANDLER_H
#define MACDOCKICONHANDLER_H

#include <QtCore/QObject>

class QMenu;
class QIcon;
class QWidget;
class objc_object;

/** Macintosh-specific dock icon handler.
 */
class MacDockIconHandler : public QObject
{
    Q_OBJECT
public:
    ~MacDockIconHandler();

    QMenu *dockMenu();
    void setIcon(const QIcon &icon);

    static MacDockIconHandler *instance();

    void handleDockIconClickEvent();

signals:
    void dockIconClicked();

public slots:

private:
    MacDockIconHandler();

    objc_object *m_dockIconClickEventHandler;
    QWidget *m_dummyWidget;
    QMenu *m_dockMenu;
};

#endif // MACDOCKICONCLICKHANDLER_H
