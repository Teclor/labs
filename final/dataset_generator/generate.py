from PIL import Image, ImageDraw, ImageFont
from pathlib import Path
from dataset_generator import char_helper as ch

# ------------------------------------generate letters from font------------------------------------------------------ #
letters = 'абвгдежзийклмнопрстуфхцчшщъыьэюяАБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ1234567890.:,;\'"(!?)+-*/='
# ------------------------------------get latin file names------------------------------------------------------------ #
chars_map = ch.chars_to_file_names()
img_size = 64  # size of the result picture
letters_initial_dir = 'letters_initial'

# ------------------------------------font names to real font names in windows---------------------------------------- #
fonts = {'Arial': 'Arial', 'Times New Roman': 'Times', 'Calibri': 'Calibril'}
sizes = [48, 52, 56]  # list of text sizes in points
for s in sizes:
    for f in fonts:
        for l in letters:
            im = Image.new('RGB', (img_size, img_size), color='white')
            font = ImageFont.truetype('C:\\Windows\\Fonts\\{}.ttf'.format(fonts[f]), size=s)
            draw_text = ImageDraw.Draw(im)
            w, h = draw_text.textsize(l, font=font)
            h += int(h * 0.21)  # line height is normally ~20% larger than the glyphs/characters(+ some trial and error)
            draw_text.text(
                ((img_size - w) / 2, (img_size - h) / 2),
                l,
                font=font,
                fill='black')
            # ------------------------------------letters_dir/size/font/letter/letter.jpg----------------------------- #
            Path('{}\\{}\\{}\\{}'.format(letters_initial_dir, s, f, chars_map[l])).mkdir(parents=True, exist_ok=True)
            im.save('{}\\{}\\{}\\{}\\{}_0000.jpg'.format(letters_initial_dir, s, f, chars_map[l], chars_map[l]))
