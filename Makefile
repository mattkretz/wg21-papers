SUBDIRS := $(wildcard */.)
TARGETS := all clean final
SUBDIRTARGETS := $(foreach t,$(TARGETS),$(addsuffix $t,$(SUBDIRS)))
.PHONY: $(TARGETS) $(SUBDIRTARGETS)

$(TARGETS):%:$(addsuffix %,$(SUBDIRS))

$(SUBDIRTARGETS):
	$(MAKE) -C $(@D) $(@F:.%=%)

