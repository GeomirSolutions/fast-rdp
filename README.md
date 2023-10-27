# Ramer-Douglas-Peucker Algorithm

>   Ускоренная (~8000x) версия python-библиотеки [rdp](https://pypi.org/project/rdp/).

Быстрая C++ реализация алгоритма Рамера-Дугласа-Пейкера (Ramer 1972; Douglas and Peucker 1973) для 2D- и 3D-данных.

Алгоритм Рамера-Дугласа-Пейкера — это алгоритм, позволяющий уменьшить число точек кривой, аппроксимированной большей серией точек..


## Установка

### с помощью pip

```bash
pip install -U fast-rdp
```

### их исходников

```bash
git clone --recursive https://github.com/GeomirSolutions/fast-rdp
pip install ./fast-rdp
```

или

```
pip install git+https://github.com/GeomirSolutions/fast-rdp.git
```

(можно сбилдить wheels для дальнейшего использования ` pip wheel git+https://github.com/GeomirSolutions/fast-rdp.git`)

## Использование

Проверка работоспособности: `python -c 'from fast_rdp import rdp; print(rdp([[1, 1], [2, 2], [3, 3], [4, 4]]))'`

Пример Python:

```python
from fast_rdp import rdp

rdp([[1, 1], [2, 2], [3, 3], [4, 4]])
[[1, 1], [4, 4]]
```

Для epsilon=0.5:

```python
rdp([[1, 1], [1, 1.1], [2, 2]], epsilon=0.5)
[[1.0, 1.0], [2.0, 2.0]]
```

Пример Numpy:

```python
import numpy as np
from fast_rdp import rdp

rdp(np.array([1, 1, 2, 2, 3, 3, 4, 4]).reshape(4, 2))
>> array([[1, 1],
          [4, 4]])
```

## Тесты

```
make python_install
make python_test
```

## Примечания

Проект основан на [pybind11-rdp](https://github.com/cubao/pybind11-rdp)

© Все права защищены, ООО ГеомирАгро, 2023
