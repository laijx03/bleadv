CC = gcc
CFLAGS = -MD -ggdb -Os -Wfatal-errors -fsigned-char -ffunction-sections -fdata-sections -fno-common -std=gnu11 -m32
SOURCES = $(wildcard src/*.c)
ASMS = $(patsubst src/%.c, obj/%.s, $(SOURCES))
TARGET = libasm.a

.PHONY: clean

$(TARGET): $(ASMS)
	ar rc $@ $^

obj/%.s: src/%.c
	$(CC) -S -o $@ $(CFLAGS) $^

clean:
	rm -f $(TARGET) $(ASMS)

destclean:
	rm -f $(TARGET) $(ASMS) obj/*.d

-include obj/*.d
