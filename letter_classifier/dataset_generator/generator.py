from PIL import Image, ImageDraw, ImageFont
from pathlib import Path
from letter_classifier.dataset_generator import char_helper as ch
from letter_classifier.settings import Settings


class Generator:

    def __init__(self, sizes=None):
        self.settings = Settings()
        # ------------------------------------generate chars list----------------------------------------------------- #
        self.chars = ch.get_chars()
        # ------------------------------------get latin file names---------------------------------------------------- #
        self.chars_map = ch.get_chars_to_file_names()
        self.img_size = self.settings.get('IMAGE_SIZE')
        self.fonts = self.settings.get('FONT_LIST')
        self.sizes = [48, 52, 56] if sizes is None else sizes  # list of text sizes in points
        self.letters_initial_dir = self.settings.get('DATASET_PATH') + '_initial'

    def __len__(self):
        return len(self.sizes) * len(self.chars) * len(self.fonts)

    def generate(self):
        print('[INFO] start generating for {} objects...'.format(len(self)))
        for s in self.sizes:
            for f in self.fonts:
                for char in self.chars:
                    im = Image.new('RGB', (self.img_size, self.img_size), color='white')
                    font = ImageFont.truetype('{}\\fonts\\{}.ttf'.format(Path(__file__).absolute().parent, self.fonts[f]), size=s)
                    draw_text = ImageDraw.Draw(im)
                    w, h = draw_text.textsize(char, font=font)
                    # line height is normally ~20% larger than the glyphs/characters(+ some trial and error)
                    h += int(h * 0.21)
                    draw_text.text(
                        ((self.img_size - w) / 2, (self.img_size - h) / 2),
                        char,
                        font=font,
                        fill='black')
                    # ------------------------------------letters_dir/size/font/letter/letter.jpg--------------------- #
                    Path('{}\\{}\\{}\\{}'.format(self.letters_initial_dir, s, f, self.chars_map[char])).mkdir(
                        parents=True,
                        exist_ok=True)
                    im.save('{}\\{}\\{}\\{}\\{}_0000.jpg'.format(self.letters_initial_dir, s, f, self.chars_map[char],
                                                                 self.chars_map[char]))
        print('[INFO] generation is done')
