cln-rpc-wrongdir:
	$(MAKE) -C .. cln-rpc-all

CLN_RPC_EXAMPLES := target/${RUST_PROFILE}/examples/cln-rpc-getinfo
CLN_RPC_GENALL = cln-rpc/src/model.rs
CLN_RPC_SOURCES = $(shell find cln-rpc -name *.rs) ${CLN_RPC_GENALL}
JSON_SCHEMAS = $(wildcard doc/schemas/*.request.json doc/schemas/*.schema.json)
DEFAULT_TARGETS += $(CLN_RPC_EXAMPLES) $(CLN_RPC_GENALL)

$(CLN_RPC_GENALL): $(JSON_SCHEMAS)
	PYTHONPATH=contrib/msggen python3 contrib/msggen/msggen/__main__.py

target/${RUST_PROFILE}/examples/cln-rpc-getinfo: $(shell find cln-rpc -name *.rs)
	cargo build ${CARGO_OPTS} --example cln-rpc-getinfo

target/${RUST_PROFILE}/examples/cln-plugin-startup: $(shell find cln-rpc -name *.rs)
	cargo build ${CARGO_OPTS} --example cln-plugin-startup

target/${RUST_PROFILE}/examples/cln-plugin-reentrant: $(shell find plugins/examples -name *.rs)
	cargo build ${CARGO_OPTS} --example cln-plugin-reentrant


cln-rpc-all: ${CLN_RPC_GEN_ALL} ${CLN_RPC_EXAMPLES}
