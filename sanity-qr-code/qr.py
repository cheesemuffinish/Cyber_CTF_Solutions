#!/usr/bin/env python

# coding: utf-8

#

# pyqrcode sample decoder



import sys, qrcode



d = qrcode.Decoder()

if d.decode('qrcode.png'):

    print 'result: ' + d.result

else:

    print 'error: ' + d.error