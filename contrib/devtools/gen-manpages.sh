#!/bin/sh

TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
SRCDIR=${SRCDIR:-$TOPDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

PRESIDENTIELCOIND=${PRESIDENTIELCOIND:-$SRCDIR/presidentielcoind}
PRESIDENTIELCOINCLI=${PRESIDENTIELCOINCLI:-$SRCDIR/presidentielcoin-cli}
PRESIDENTIELCOINTX=${PRESIDENTIELCOINTX:-$SRCDIR/presidentielcoin-tx}
PRESIDENTIELCOINQT=${PRESIDENTIELCOINQT:-$SRCDIR/qt/presidentielcoin-qt}

[ ! -x $PRESIDENTIELCOIND ] && echo "$PRESIDENTIELCOIND not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
SYSVER=($($PRESIDENTIELCOINCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for presidentielcoind if --version-string is not set,
# but has different outcomes for presidentielcoin-qt and presidentielcoin-cli.
echo "[COPYRIGHT]" > footer.h2m
$PRESIDENTIELCOIND --version | sed -n '1!p' >> footer.h2m

for cmd in $PRESIDENTIELCOIND $PRESIDENTIELCOINCLI $PRESIDENTIELCOINTX $PRESIDENTIELCOINQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${SYSVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${SYSVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
