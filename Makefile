all:
	@echo nothing special

clean:
	rm -rf build dist wheelhouse *.egg-info
force_clean:
	docker run --rm -v `pwd`:`pwd` -w `pwd` -it alpine/make make clean
.PHONY: clean force_clean

lint:
	pre-commit run -a
lint_install:
	pre-commit install

build:
	mkdir -p build && cd build && \
	cmake .. && make
.PHONY: build

DOCKER_TAG_WINDOWS ?= ghcr.io/GeomirSolutions/build-env-windows-x64:latest
DOCKER_TAG_LINUX ?= ghcr.io/GeomirSolutions/build-env-manylinux2014-x64:latest
DOCKER_TAG_MACOS ?= ghcr.io/GeomirSolutions/build-env-macos-arm64:latest

test_in_win:
	docker run --rm -w `pwd` -v `pwd`:`pwd` -v `pwd`/build/win:`pwd`/build -it $(DOCKER_TAG_WINDOWS) bash
test_in_mac:
	docker run --rm -w `pwd` -v `pwd`:`pwd` -v `pwd`/build/mac:`pwd`/build -it $(DOCKER_TAG_MACOS) bash
test_in_linux:
	docker run --rm -w `pwd` -v `pwd`:`pwd` -v `pwd`/build/linux:`pwd`/build -it $(DOCKER_TAG_LINUX) bash

PYTHON ?= python3
python_install:
	$(PYTHON) setup.py install --force
python_build:
	$(PYTHON) setup.py bdist_wheel
python_sdist:
	$(PYTHON) setup.py sdist
	# tar -tvf dist/fast_rdp-*.tar.gz
python_test:
	$(PYTHON) -m pip install pytest rdp
	$(PYTHON) -c 'from fast_rdp import rdp; print(rdp([[1, 1], [2, 2], [3, 3], [4, 4]]))'
	pytest tests
	$(PYTHON) test.py

# conda create -y -n py310 python=3.10
# conda create -y -n py310 python=3.11
# conda create -y -n py310 python=3.12
# conda env list
python_build_py310:
	PYTHON=python conda run --no-capture-output -n py310 make python_build
python_build_py311:
	PYTHON=python conda run --no-capture-output -n py311 make python_build
python_build_py312:
	PYTHON=python conda run --no-capture-output -n py312 make python_build
python_build_all: python_build_py310 python_build_py311 python_build_py312
python_build_all_in_linux:
	docker run --rm -w `pwd` -v `pwd`:`pwd` -v `pwd`/build/win:`pwd`/build -it $(DOCKER_TAG_LINUX) make python_build_all
	make repair_wheels && rm -rf dist/*.whl && mv wheelhouse/*.whl dist && rm -rf wheelhouse
python_build_all_in_macos: python_build_py310 python_build_py311 python_build_py312
python_build_all_in_windows: python_build_all

repair_wheels:
	python -m pip install auditwheel # sudo apt install patchelf
	ls dist/* | xargs -n1 auditwheel repair --plat manylinux2014_x86_64

pypi_remote ?= pypi
upload_wheels:
	python -m pip install twine
	twine upload dist/*.whl -r $(pypi_remote)

tar.gz:
	tar -cvz --exclude .git -f ../fast-rdp.tar.gz .
	ls -alh ../fast-rdp.tar.gz

echo-%  : ; @echo -n $($*)
Echo-%  : ; @echo $($*)
ECHO-%  : ; @echo $* = $($*)
echo-Tab: ; @echo -n '    '
