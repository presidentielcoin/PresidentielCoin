// Copyright (c) 2016 The Presidentielcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef PRESIDENTIELCOIN_QT_TEST_RPC_NESTED_TESTS_H
#define PRESIDENTIELCOIN_QT_TEST_RPC_NESTED_TESTS_H

#include <QObject>
#include <QTest>

#include "txdb.h"
#include "txmempool.h"

class RPCNestedTests : public QObject
{
    Q_OBJECT

    private Q_SLOTS:
    void rpcNestedTests();

private:
    CCoinsViewDB *pcoinsdbview;
};

#endif // PRESIDENTIELCOIN_QT_TEST_RPC_NESTED_TESTS_H
