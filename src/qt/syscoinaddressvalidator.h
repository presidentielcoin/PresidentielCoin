// Copyright (c) 2011-2014 The Presidentielcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef PRESIDENTIELCOIN_QT_PRESIDENTIELCOINADDRESSVALIDATOR_H
#define PRESIDENTIELCOIN_QT_PRESIDENTIELCOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class PresidentielcoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit PresidentielcoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Presidentielcoin address widget validator, checks for a valid presidentielcoin address.
 */
class PresidentielcoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit PresidentielcoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // PRESIDENTIELCOIN_QT_PRESIDENTIELCOINADDRESSVALIDATOR_H
