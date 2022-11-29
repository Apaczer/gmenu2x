PLATFORM = trimui

CROSS_COMPILE ?= /opt/trimui-toolchain/bin/arm-linux-

export CROSS_COMPILE

CFLAGS += -Os
CFLAGS += -DTARGET_TRIMUI

LDFLAGS = -ltinyalsa

include gmenunx.mk
