# ============================================================
# ps_graph — paths
# Edit here, then run make to regenerate the script.
# ============================================================

PUSH_SWAP	= $(abspath ../../push_swap)
PS_GEN		= $(abspath ../ps_gen/ps_gen)

SED_FLAGS = \
	-e 's|__PUSH_SWAP__|$(PUSH_SWAP)|g' \
	-e 's|__PS_GEN__|$(PS_GEN)|g'

all: ps_graph

ps_graph: ps_graph.tpl
	sed $(SED_FLAGS) $< > $@
	chmod +x $@

clean:
	rm -f ps_graph

re: clean all

.PHONY: all clean re
