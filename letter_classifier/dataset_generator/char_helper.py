# --------------get cyrillic chars to latin equivalents map because OpenCV can't handle unicode file names------------ #
def get_chars_to_file_names():
    return {
        'а': 'sm-a',
        'б': 'sm-b',
        'в': 'sm-v',
        'г': 'sm-g',
        'д': 'sm-d',
        'е': 'sm-e',
        'ж': 'sm-zh',
        'з': 'sm-z',
        'и': 'sm-i',
        'й': 'sm-iy',
        'к': 'sm-k',
        'л': 'sm-l',
        'м': 'sm-m',
        'н': 'sm-n',
        'о': 'sm-o',
        'п': 'sm-p',
        'р': 'sm-r',
        'с': 'sm-s',
        'т': 'sm-t',
        'у': 'sm-u',
        'ф': 'sm-f',
        'х': 'sm-h',
        'ц': 'sm-c',
        'ч': 'sm-ch',
        'ш': 'sm-sh',
        'щ': 'sm-sha',
        'ъ': 'sm-hard-sign',
        'ы': 'sm-ii',
        'ь': 'sm-soft-sign',
        'э': 'sm-ee',
        'ю': 'sm-yu',
        'я': 'sm-ya',
        'А': 'big-a',
        'Б': 'big-b',
        'В': 'big-v',
        'Г': 'big-g',
        'Д': 'big-d',
        'Е': 'big-e',
        'Ж': 'big-zh',
        'З': 'big-z',
        'И': 'big-i',
        'Й': 'big-iy',
        'К': 'big-k',
        'Л': 'big-l',
        'М': 'big-m',
        'Н': 'big-n',
        'О': 'big-o',
        'П': 'big-p',
        'Р': 'big-r',
        'С': 'big-s',
        'Т': 'big-t',
        'У': 'big-u',
        'Ф': 'big-f',
        'Х': 'big-h',
        'Ц': 'big-c',
        'Ч': 'big-ch',
        'Ш': 'big-sh',
        'Щ': 'big-sha',
        'Ъ': 'big-hard-sign',
        'Ы': 'big-ii',
        'Ь': 'big-soft-sign',
        'Э': 'big-ee',
        'Ю': 'big-yu',
        'Я': 'big-ya',
        '.': 'dot',
        ':': 'colon',
        ',': 'comma',
        ';': 'semicolon',
        '\'': 'quote',
        '"': 'double-quote',
        '(': 'left-bracket',
        '!': 'exclamation-mark',
        '?': 'question-mark',
        ')': 'right-bracket',
        '+': 'plus',
        '-': 'minus',
        '*': 'asterisk',
        '/': 'slash',
        '=': 'equal',
        '0': '0',
        '1': '1',
        '2': '2',
        '3': '3',
        '4': '4',
        '5': '5',
        '6': '6',
        '7': '7',
        '8': '8',
        '9': '9',
    }


def get_file_names_to_chars():
    return {value: key for key, value in get_chars_to_file_names().items()}


def get_chars():
    return 'абвгдежзийклмнопрстуфхцчшщъыьэюяАБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ1234567890.:,;\'"(!?)+-*/='


def get_char_indexes():
    chars = get_chars()
    return {val: chars.index(val) for val in chars}
