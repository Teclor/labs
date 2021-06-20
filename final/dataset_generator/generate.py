from PIL import Image, ImageDraw, ImageFont
from pathlib import Path
import char_helper as ch


letters = 'абвгдежзийклмнопрстуфхцчшщъыьэюяАБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ1234567890.:,;\'"(!?)+-*/='
chars_map = ch.chars_to_file_names()

fonts = {'Arial': 'Arial', 'Times New Roman': 'Times', 'Calibri': 'Calibril'}
sizes = [48, 52, 54, 56]
for s in sizes:
    for f in fonts:
        for l in letters:
            im = Image.new('RGB', (64, 64), color='#FFFFFF')
            # Создаем объект со шрифтом
            font = ImageFont.truetype('C:\\Windows\\Fonts\\{}.ttf'.format(fonts[f]), size=s)
            draw_text = ImageDraw.Draw(im)
            draw_text.text(
                (0, 0),
                l,
                # Добавляем шрифт к изображению
                font=font,
                fill='#000000')
            Path('letters_initial\\{}\\{}\\{}'.format(s, f, chars_map[l])).mkdir(parents=True, exist_ok=True)
            im.save('letters_initial\\{}\\{}\\{}\\{}_0000.jpg'.format(s, f, chars_map[l], chars_map[l]))
