![Testing](https://github.com/MariaMozgunova/WordCount/actions/workflows/run_tests.yaml/badge.svg)



<details open="open">
  <summary>Содержание</summary>
  <ol>
    <li><a href="#about">О лабе</a></li>
    <li><a href="#usage">Использование</a></li>
    <li><a href="#license">Лицензия</a></li>
  </ol>
</details>



## <a name="about">О лабе</a>

#### Задача
Реализовать утилиту WordCount подсчитывающую количество строк, слов и байт для указанного файла и выводить эту информацию в поток вывода.

Программа должна поддерживать следующие опции:
* `-l`, `--lines` вывод только количества строк
* `-c`, `--bytes` вывод размера файла в байтах
* `-w`, `--words` вывод количества слов

Название файла и опции передаются через аргументы командной строки в следующем формате:
`WordCount.exe [OPTIONS] path_to_file`

#### Примечание
1. Для реализации утилиты потребуется воспользоваться
стандартной библиотекой вводы\вывода ([описание](https://en.cppreference.com/w/c/io))
2. Пример того, как можно организовать парсинг
аргументов командной строки, можно посмотреть [здесь](http://www.cplusplus.com/articles/DEN36Up4/)



## <a name="usage">Использование</a>

1. Склонируйте репозиторий на локальную машину `git clone https://github.com/MariaMozgunova/WordCount.git`
2. Запустите утилиту `WordCount.exe [OPTIONS] path_to_file`. Смотрите допустимые опции [здесь](#about)


## <a name="license">Лицензия</a>

Данный проект имеет лицензию MIT. Смотрите файл `LICENSE` для более подробной информации.
