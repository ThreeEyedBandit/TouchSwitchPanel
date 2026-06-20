/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: --bpp 1 --size 16 --font C:/Users/Matt/Desktop/PlatformIO Projects/Touch Switch Panel/TouchPanelUI/assets/Qilka-Bold copy.otf -o C:/Users/Matt/Desktop/PlatformIO Projects/Touch Switch Panel/TouchPanelUI/assets\ui_font_Font16.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "ui.h"

#ifndef UI_FONT_FONT16
#define UI_FONT_FONT16 1
#endif

#if UI_FONT_FONT16

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xff, 0xff, 0xff, 0xf1, 0xff,

    /* U+0022 "\"" */
    0xde, 0xf6,

    /* U+0023 "#" */
    0x3f, 0x1f, 0x8f, 0xdf, 0xff, 0xff, 0xfc, 0xfc,
    0x7e, 0xff, 0xff, 0xff, 0xe7, 0xe3, 0xf0,

    /* U+0024 "$" */
    0xe, 0x1, 0xc0, 0xfc, 0x3f, 0xcf, 0xf9, 0xff,
    0x3f, 0x87, 0xfc, 0x7f, 0xc9, 0xfb, 0xff, 0xff,
    0xe7, 0xfc, 0x7f, 0x3, 0x80, 0x70,

    /* U+0025 "%" */
    0x3c, 0x60, 0x1f, 0x9c, 0xf, 0xf6, 0x3, 0x9f,
    0x80, 0xe7, 0xc0, 0x3f, 0xf3, 0xc7, 0xfd, 0xf8,
    0xf6, 0xff, 0x3, 0xb9, 0xc0, 0xee, 0x70, 0x33,
    0xfc, 0x1c, 0x7e, 0x6, 0xf, 0x0,

    /* U+0026 "&" */
    0x3c, 0xf, 0xc3, 0xfc, 0x73, 0x8f, 0xf1, 0xff,
    0x9f, 0xf7, 0xfe, 0xff, 0xdc, 0xfb, 0xfe, 0x3f,
    0xe3, 0xd8,

    /* U+0027 "'" */
    0xfc,

    /* U+0028 "(" */
    0x1c, 0xf7, 0x9c, 0xe3, 0x8e, 0x38, 0xe3, 0x8e,
    0x1c, 0x78, 0xf1, 0xc0,

    /* U+0029 ")" */
    0x61, 0xc3, 0x8e, 0x1c, 0x71, 0xc7, 0x1c, 0x71,
    0xce, 0x39, 0xc6, 0x0,

    /* U+002A "*" */
    0xff, 0xa0,

    /* U+002B "+" */
    0x38, 0x73, 0xff, 0xff, 0xe7, 0xe, 0x0,

    /* U+002C "," */
    0xff, 0xa0,

    /* U+002D "-" */
    0xff, 0xff, 0xf8,

    /* U+002E "." */
    0xff, 0x80,

    /* U+002F "/" */
    0x4, 0x1c, 0x30, 0xe1, 0xc3, 0xe, 0x18, 0x70,
    0xe1, 0x87, 0x4, 0x0,

    /* U+0030 "0" */
    0xf, 0x3, 0xfc, 0x7f, 0xe7, 0x1e, 0xf0, 0xfe,
    0x7, 0xe0, 0x7e, 0x7, 0xf0, 0xf7, 0x1e, 0x7f,
    0xe3, 0xfc, 0xf, 0x0,

    /* U+0031 "1" */
    0xff, 0xfe, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73,
    0x80,

    /* U+0032 "2" */
    0x3e, 0x3f, 0x9f, 0xee, 0x70, 0x38, 0x3c, 0x7c,
    0x7e, 0x7c, 0x78, 0x3f, 0xff, 0xf7, 0xf8,

    /* U+0033 "3" */
    0x3e, 0x3f, 0xbf, 0xec, 0x70, 0x38, 0xfc, 0x7c,
    0x3f, 0x63, 0xf9, 0xff, 0xef, 0xe3, 0xe0,

    /* U+0034 "4" */
    0x1, 0x80, 0x78, 0x1f, 0x7, 0xe1, 0xfc, 0x7f,
    0x9f, 0x77, 0xff, 0xff, 0xef, 0xfc, 0x7, 0x0,
    0xe0, 0x1c,

    /* U+0035 "5" */
    0x7f, 0x7f, 0xbf, 0xdc, 0xe, 0x7, 0xf3, 0xfc,
    0xff, 0x3, 0xb1, 0xff, 0xef, 0xe3, 0xe0,

    /* U+0036 "6" */
    0x1e, 0x1f, 0x9f, 0xde, 0x4f, 0xe7, 0xfb, 0xff,
    0xe7, 0xf3, 0xf9, 0xdf, 0xef, 0xe1, 0xe0,

    /* U+0037 "7" */
    0xff, 0xbf, 0xff, 0xfc, 0x1e, 0xf, 0x83, 0xc0,
    0xe0, 0x78, 0x1c, 0x7, 0x1, 0xc0, 0x70, 0x1c,
    0x0,

    /* U+0038 "8" */
    0x3e, 0x3f, 0xbf, 0xfc, 0x7e, 0x3f, 0xfd, 0xfd,
    0xff, 0xe3, 0xf1, 0xff, 0xef, 0xe3, 0xe0,

    /* U+0039 "9" */
    0x3e, 0x1f, 0xcf, 0xfb, 0x9e, 0xe7, 0xb9, 0xef,
    0xf9, 0xfe, 0x3f, 0x89, 0xe7, 0xf1, 0xfc, 0x3c,
    0x0,

    /* U+003A ":" */
    0xff, 0x80, 0x3f, 0xe0,

    /* U+003B ";" */
    0xff, 0x80, 0x3f, 0xe8,

    /* U+003C "<" */
    0x7, 0x1f, 0x7c, 0xe0, 0x7c, 0x1f, 0x7,

    /* U+003D "=" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xc0,

    /* U+003E ">" */
    0xe0, 0xf8, 0x3e, 0x7, 0x3e, 0xf8, 0xe0,

    /* U+003F "?" */
    0x3e, 0x3f, 0xbf, 0xec, 0x70, 0x38, 0xfc, 0xfc,
    0x7c, 0x3c, 0x1e, 0xf, 0x3, 0x0, 0x0, 0xc0,
    0xf0, 0x30,

    /* U+0040 "@" */
    0x7, 0xc0, 0x7f, 0xc3, 0xff, 0x1e, 0x1e, 0x77,
    0xfb, 0xbf, 0x7f, 0xfd, 0xff, 0x77, 0xfd, 0xdf,
    0xff, 0x7f, 0xff, 0xdf, 0xfe, 0x3f, 0x70, 0x7c,
    0x0, 0xf0, 0x0,

    /* U+0041 "A" */
    0xc, 0x1, 0xc0, 0x78, 0xf, 0x81, 0xf0, 0x7f,
    0xe, 0xe3, 0xdc, 0x7f, 0xcf, 0xfb, 0xff, 0xf0,
    0xf6, 0xc,

    /* U+0042 "B" */
    0x7e, 0x3f, 0xcf, 0xfb, 0x9e, 0xe7, 0xbf, 0xef,
    0xfb, 0xff, 0xe1, 0xf8, 0x7f, 0xff, 0xfe, 0x7f,
    0x0,

    /* U+0043 "C" */
    0x1f, 0x7, 0xf9, 0xff, 0x38, 0xef, 0x1, 0xc0,
    0x38, 0x7, 0x0, 0xf0, 0xe, 0x3d, 0xff, 0x9f,
    0xe0, 0xf8,

    /* U+0044 "D" */
    0x7c, 0x7f, 0x3f, 0xdc, 0xee, 0x3f, 0x1f, 0x8f,
    0xc7, 0xe3, 0xf3, 0xbf, 0xdf, 0xcf, 0xc0,

    /* U+0045 "E" */
    0x7f, 0xbf, 0xff, 0xfb, 0x80, 0xe0, 0x3f, 0xcf,
    0xf3, 0xfc, 0xe0, 0x38, 0xf, 0xfb, 0xff, 0x7f,
    0x80,

    /* U+0046 "F" */
    0x7f, 0xbf, 0xff, 0xfb, 0x80, 0xe0, 0x3f, 0xcf,
    0xf3, 0xfc, 0xe0, 0x38, 0xe, 0x3, 0x80, 0xe0,
    0x0,

    /* U+0047 "G" */
    0x1f, 0x7, 0xf1, 0xff, 0x38, 0xef, 0x9, 0xcf,
    0xbb, 0xf7, 0x3f, 0xf1, 0xee, 0x3d, 0xff, 0x1f,
    0xe0, 0xf0,

    /* U+0048 "H" */
    0xc3, 0xf1, 0xf8, 0xfc, 0x7e, 0x3f, 0xff, 0xff,
    0xff, 0xe3, 0xf1, 0xf8, 0xfc, 0x7e, 0x38,

    /* U+0049 "I" */
    0xff, 0xff, 0xff, 0xff, 0xfe,

    /* U+004A "J" */
    0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7,
    0x67, 0xf7, 0x7f, 0x7e, 0x3c,

    /* U+004B "K" */
    0xe3, 0x73, 0xfb, 0xff, 0xef, 0xe7, 0xe3, 0xf1,
    0xf8, 0xfe, 0x7f, 0xbb, 0xdc, 0xfe, 0x30,

    /* U+004C "L" */
    0xc0, 0x38, 0xe, 0x3, 0x80, 0xe0, 0x38, 0xe,
    0x3, 0x80, 0xe0, 0x38, 0xf, 0xfb, 0xff, 0x7f,
    0x80,

    /* U+004D "M" */
    0x60, 0x6e, 0x7, 0xf0, 0xff, 0xf, 0xf9, 0xff,
    0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef,
    0x7e, 0xf7, 0xe6, 0x70,

    /* U+004E "N" */
    0xe3, 0xf1, 0xfc, 0xff, 0x7f, 0xbf, 0xff, 0xff,
    0xff, 0xef, 0xf7, 0xf9, 0xfc, 0x7e, 0x38,

    /* U+004F "O" */
    0xf, 0x3, 0xfc, 0x7f, 0xe7, 0xe, 0xf0, 0xfe,
    0x7, 0xe0, 0x7e, 0x7, 0xe0, 0x77, 0xe, 0x7f,
    0xe3, 0xfc, 0xf, 0x0,

    /* U+0050 "P" */
    0xff, 0x3f, 0xef, 0xff, 0x87, 0xe1, 0xf8, 0x7f,
    0xff, 0xfe, 0xfe, 0x38, 0xe, 0x3, 0x80, 0xe0,
    0x0,

    /* U+0051 "Q" */
    0xf, 0x3, 0xfc, 0x7f, 0xe7, 0xe, 0xe0, 0xfe,
    0x7, 0xe3, 0x7e, 0x3f, 0xe7, 0xf7, 0x3e, 0x7f,
    0xe3, 0xfe, 0xf, 0xe0, 0xe,

    /* U+0052 "R" */
    0xff, 0x3f, 0xef, 0xff, 0x87, 0xe1, 0xf8, 0x7f,
    0xff, 0xfe, 0xff, 0x3b, 0xee, 0x7f, 0x8f, 0xe1,
    0x80,

    /* U+0053 "S" */
    0x3e, 0x1f, 0xef, 0xfb, 0x8e, 0xe0, 0x3f, 0xc7,
    0xf8, 0xff, 0x63, 0xfc, 0x77, 0xfd, 0xfe, 0x1f,
    0x0,

    /* U+0054 "T" */
    0xff, 0xff, 0xff, 0xfc, 0x38, 0xe, 0x3, 0x80,
    0xe0, 0x38, 0xe, 0x3, 0x80, 0xe0, 0x38, 0xe,
    0x0,

    /* U+0055 "U" */
    0xc3, 0xf1, 0xf8, 0xfc, 0x7e, 0x3f, 0x1f, 0x8f,
    0xc7, 0xe3, 0xf1, 0xff, 0xef, 0xe1, 0xe0,

    /* U+0056 "V" */
    0x60, 0xdc, 0x3f, 0xc7, 0xb8, 0xe7, 0xbc, 0xf7,
    0xf, 0xe1, 0xfc, 0x1f, 0x3, 0xe0, 0x7c, 0x7,
    0x0, 0xe0,

    /* U+0057 "W" */
    0x61, 0x87, 0xe3, 0xc7, 0xf3, 0xc7, 0x73, 0xcf,
    0x7f, 0xee, 0x7f, 0xfe, 0x3f, 0xfe, 0x3f, 0xfc,
    0x1f, 0xfc, 0x1f, 0x7c, 0x1e, 0x78, 0xe, 0x78,
    0xe, 0x30,

    /* U+0058 "X" */
    0x60, 0xde, 0x3f, 0xef, 0x3d, 0xe3, 0xf8, 0x3e,
    0x7, 0xc0, 0xf8, 0x3f, 0x8f, 0x7b, 0xef, 0x78,
    0xf6, 0xc,

    /* U+0059 "Y" */
    0x60, 0xce, 0x39, 0xef, 0x3d, 0xe3, 0xf8, 0x3e,
    0x3, 0x80, 0x70, 0xe, 0x1, 0xc0, 0x38, 0x7,
    0x0, 0xe0,

    /* U+005A "Z" */
    0xff, 0xbf, 0xff, 0xfc, 0x1e, 0xf, 0x83, 0xc1,
    0xf0, 0x78, 0x3e, 0xf, 0x7, 0xfd, 0xff, 0x3f,
    0xc0,

    /* U+005B "[" */
    0x7f, 0xff, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce,
    0x7f, 0xef,

    /* U+005C "\\" */
    0x61, 0xc1, 0x83, 0x87, 0x7, 0xe, 0xc, 0x1c,
    0x38, 0x30, 0x70, 0x60,

    /* U+005D "]" */
    0x77, 0xde, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73,
    0xbd, 0xef,

    /* U+005E "^" */
    0x0, 0xc7, 0x1e, 0x5b, 0x3c, 0xc0,

    /* U+005F "_" */
    0xff, 0xff, 0xf8,

    /* U+0061 "a" */
    0x1f, 0xbf, 0xff, 0xfc, 0x7e, 0x3f, 0x1f, 0xfe,
    0xff, 0x1f, 0x80,

    /* U+0062 "b" */
    0xe0, 0x70, 0x38, 0x1c, 0xf, 0xe7, 0xfb, 0xff,
    0xc7, 0xe3, 0xf1, 0xff, 0xff, 0xef, 0xe0,

    /* U+0063 "c" */
    0x3c, 0xff, 0xff, 0x2e, 0x1c, 0x3f, 0xbf, 0x3c,

    /* U+0064 "d" */
    0x3, 0x81, 0xc0, 0xe0, 0x71, 0xfb, 0xff, 0xff,
    0xc7, 0xe3, 0xf1, 0xff, 0xef, 0xf1, 0xf8,

    /* U+0065 "e" */
    0x3c, 0x7e, 0xff, 0xf7, 0xff, 0xf0, 0xfe, 0x7e,
    0x3e,

    /* U+0066 "f" */
    0x1e, 0x7c, 0xff, 0xff, 0xff, 0xce, 0x1c, 0x38,
    0x70, 0xe1, 0xc0,

    /* U+0067 "g" */
    0x3f, 0xbf, 0xff, 0xfc, 0x7e, 0x3f, 0x1f, 0xfe,
    0xff, 0x1f, 0x89, 0xcf, 0xe7, 0xe1, 0xe0,

    /* U+0068 "h" */
    0xe0, 0xe0, 0xe0, 0xe0, 0xfc, 0xfe, 0xfe, 0xe7,
    0xe7, 0xe7, 0xe7, 0xe7, 0xe7,

    /* U+0069 "i" */
    0xff, 0x8f, 0xff, 0xff, 0xfe,

    /* U+006A "j" */
    0x1c, 0x71, 0xc0, 0x1c, 0x71, 0xc7, 0x1c, 0x71,
    0xc7, 0x1c, 0x77, 0xfe, 0x70,

    /* U+006B "k" */
    0xe0, 0xe0, 0xe0, 0xe0, 0xe7, 0xef, 0xff, 0xfe,
    0xfc, 0xfe, 0xff, 0xef, 0xe7,

    /* U+006C "l" */
    0xff, 0xff, 0xff, 0xff, 0xfe,

    /* U+006D "m" */
    0xfd, 0xe7, 0xff, 0xbf, 0xff, 0xce, 0x7e, 0x73,
    0xf3, 0x9f, 0x9c, 0xfc, 0xe7, 0xe7, 0x38,

    /* U+006E "n" */
    0xfc, 0xfe, 0xff, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7,
    0xe7,

    /* U+006F "o" */
    0x3e, 0x3f, 0xbf, 0xfc, 0x7e, 0x3f, 0x1f, 0xfe,
    0xfe, 0x3e, 0x0,

    /* U+0070 "p" */
    0xfc, 0x7f, 0xbf, 0xdc, 0x7e, 0x3f, 0x1f, 0xff,
    0xfe, 0xfe, 0x70, 0x38, 0x1c, 0x0,

    /* U+0071 "q" */
    0x1f, 0xbf, 0xff, 0xfc, 0x7e, 0x3f, 0x1f, 0xfe,
    0xff, 0x3f, 0x81, 0xc0, 0xe0, 0x70,

    /* U+0072 "r" */
    0xfd, 0xff, 0xff, 0x3e, 0x1c, 0x38, 0x70, 0xe0,

    /* U+0073 "s" */
    0x78, 0xfc, 0xfe, 0xe4, 0x3e, 0xc7, 0xff, 0xff,
    0x7c,

    /* U+0074 "t" */
    0x38, 0x70, 0xe7, 0xff, 0xff, 0xce, 0x1c, 0x38,
    0x7c, 0x78, 0x70,

    /* U+0075 "u" */
    0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xff, 0x7f,
    0x3f,

    /* U+0076 "v" */
    0x63, 0x7b, 0xfd, 0xef, 0xe7, 0xf1, 0xf0, 0xf8,
    0x38, 0x1c, 0x0,

    /* U+0077 "w" */
    0x67, 0x37, 0xbb, 0xff, 0xfe, 0xff, 0xe7, 0xff,
    0x1f, 0xf0, 0xff, 0x83, 0xb8, 0x1d, 0xc0,

    /* U+0078 "x" */
    0x63, 0xf7, 0x7f, 0x7e, 0x3c, 0x7e, 0x7f, 0xf7,
    0x67,

    /* U+0079 "y" */
    0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xff, 0x7f,
    0x3f, 0x67, 0x7f, 0x7e, 0x3c,

    /* U+007A "z" */
    0x7f, 0xbf, 0xdf, 0xe3, 0xe1, 0xe1, 0xe1, 0xfc,
    0xff, 0x7f, 0x0,

    /* U+007B "{" */
    0x3b, 0xde, 0xe7, 0x39, 0xde, 0xf7, 0x9c, 0xe7,
    0x3d, 0xe7,

    /* U+007C "|" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xc0,

    /* U+007D "}" */
    0xe7, 0xbc, 0xe7, 0x39, 0xcf, 0x7b, 0xdc, 0xe7,
    0x7b, 0xdc
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 69, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 79, .box_w = 3, .box_h = 16, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 7, .adv_w = 103, .box_w = 5, .box_h = 3, .ofs_x = 1, .ofs_y = 10},
    {.bitmap_index = 9, .adv_w = 167, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 24, .adv_w = 184, .box_w = 11, .box_h = 16, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 46, .adv_w = 301, .box_w = 18, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 76, .adv_w = 198, .box_w = 11, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 94, .adv_w = 55, .box_w = 2, .box_h = 3, .ofs_x = 1, .ofs_y = 10},
    {.bitmap_index = 95, .adv_w = 116, .box_w = 6, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 107, .adv_w = 116, .box_w = 6, .box_h = 15, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 119, .adv_w = 80, .box_w = 3, .box_h = 4, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 121, .adv_w = 126, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 128, .adv_w = 69, .box_w = 3, .box_h = 4, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 130, .adv_w = 125, .box_w = 7, .box_h = 3, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 133, .adv_w = 69, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 135, .adv_w = 114, .box_w = 7, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 147, .adv_w = 216, .box_w = 12, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 167, .adv_w = 102, .box_w = 5, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 176, .adv_w = 170, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 191, .adv_w = 165, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 206, .adv_w = 195, .box_w = 11, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 224, .adv_w = 165, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 239, .adv_w = 171, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 254, .adv_w = 172, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 271, .adv_w = 166, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 286, .adv_w = 171, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 303, .adv_w = 72, .box_w = 3, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 307, .adv_w = 72, .box_w = 3, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 311, .adv_w = 147, .box_w = 8, .box_h = 7, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 318, .adv_w = 129, .box_w = 7, .box_h = 6, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 324, .adv_w = 147, .box_w = 8, .box_h = 7, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 331, .adv_w = 157, .box_w = 9, .box_h = 16, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 349, .adv_w = 244, .box_w = 14, .box_h = 15, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 376, .adv_w = 173, .box_w = 11, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 394, .adv_w = 178, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 411, .adv_w = 181, .box_w = 11, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 429, .adv_w = 171, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 444, .adv_w = 166, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 461, .adv_w = 162, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 478, .adv_w = 184, .box_w = 11, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 496, .adv_w = 178, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 511, .adv_w = 78, .box_w = 3, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 516, .adv_w = 139, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 529, .adv_w = 157, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 544, .adv_w = 161, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 561, .adv_w = 215, .box_w = 12, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 581, .adv_w = 176, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 596, .adv_w = 204, .box_w = 12, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 616, .adv_w = 172, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 633, .adv_w = 205, .box_w = 12, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 654, .adv_w = 175, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 671, .adv_w = 174, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 688, .adv_w = 165, .box_w = 10, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 705, .adv_w = 160, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 720, .adv_w = 172, .box_w = 11, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 738, .adv_w = 263, .box_w = 16, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 764, .adv_w = 176, .box_w = 11, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 782, .adv_w = 165, .box_w = 11, .box_h = 13, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 800, .adv_w = 165, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 817, .adv_w = 98, .box_w = 5, .box_h = 16, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 827, .adv_w = 114, .box_w = 7, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 839, .adv_w = 98, .box_w = 5, .box_h = 16, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 849, .adv_w = 111, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 855, .adv_w = 108, .box_w = 7, .box_h = 3, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 858, .adv_w = 156, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 869, .adv_w = 156, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 884, .adv_w = 127, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 892, .adv_w = 156, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 907, .adv_w = 138, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 916, .adv_w = 112, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 927, .adv_w = 156, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 942, .adv_w = 154, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 955, .adv_w = 72, .box_w = 3, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 960, .adv_w = 74, .box_w = 6, .box_h = 17, .ofs_x = -2, .ofs_y = -4},
    {.bitmap_index = 973, .adv_w = 153, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 986, .adv_w = 73, .box_w = 3, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 991, .adv_w = 237, .box_w = 13, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1006, .adv_w = 154, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1015, .adv_w = 150, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1026, .adv_w = 156, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1040, .adv_w = 156, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1054, .adv_w = 135, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1062, .adv_w = 142, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1071, .adv_w = 120, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1082, .adv_w = 154, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1091, .adv_w = 143, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1102, .adv_w = 210, .box_w = 13, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1117, .adv_w = 138, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1126, .adv_w = 154, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1139, .adv_w = 144, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1150, .adv_w = 116, .box_w = 5, .box_h = 16, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1160, .adv_w = 64, .box_w = 3, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1166, .adv_w = 116, .box_w = 5, .box_h = 16, .ofs_x = 1, .ofs_y = -3}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 64, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 97, .range_length = 29, .glyph_id_start = 65,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] =
{
    0, 0, 0, 1, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0,
    0, 2, 3, 4, 5, 6, 7, 8,
    9, 5, 10, 0, 0, 0, 0, 0,
    0, 0, 11, 12, 13, 14, 15, 16,
    17, 18, 18, 19, 20, 21, 18, 18,
    14, 22, 23, 24, 25, 26, 19, 27,
    27, 20, 28, 29, 0, 0, 0, 0,
    0, 30, 31, 32, 18, 33, 34, 35,
    36, 37, 38, 39, 18, 40, 40, 41,
    41, 35, 42, 43, 44, 30, 45, 45,
    46, 35, 47, 0, 0, 0
};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] =
{
    0, 0, 0, 1, 0, 0, 0, 0,
    1, 2, 3, 4, 0, 5, 6, 5,
    7, 8, 9, 10, 11, 12, 13, 14,
    15, 16, 17, 18, 18, 0, 0, 0,
    19, 0, 20, 0, 21, 0, 0, 0,
    21, 0, 0, 22, 0, 0, 0, 0,
    21, 0, 21, 0, 0, 23, 24, 25,
    25, 26, 27, 28, 0, 29, 30, 0,
    31, 32, 0, 32, 33, 32, 34, 32,
    0, 0, 35, 0, 0, 36, 36, 32,
    37, 32, 36, 38, 39, 40, 41, 41,
    42, 40, 43, 44, 0, 30
};

/*Kern values between classes*/
static const int8_t kern_class_values[] =
{
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -26, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -18,
    0, 0, 0, 0, 0, -23, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -11, -10, -10, -2,
    -3, -2, -12, -6, -5, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -2,
    0, -3, -2, -2, 0, -2, -8, -1,
    -2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -6, -9, 0, -4, -11,
    -3, -6, -12, -4, -3, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -4,
    -9, -6, 0, -2, -2, -4, -12, -2,
    -3, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -4, -11, -9, -9, 0,
    -7, -4, -13, -5, -10, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -5,
    -10, -6, -6, 0, 0, -5, -12, -4,
    -9, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -5, -10, -6, -6, 0,
    -5, 0, -12, -4, -9, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -11,
    0, -6, -2, -13, 0, -11, 0, -5,
    -5, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -2, -10, -9, -9, -2,
    -3, -2, -12, -5, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -12, 0, -12, -30, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -12, 0, -3, 0, -21, -1,
    -18, 0, -20, 0, -12, -11, 0, 0,
    0, -10, 0, 0, 0, 0, -13, 0,
    -10, 0, 0, -5, -9, 0, -11, -9,
    0, 0, -4, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -2, -10, 0,
    0, 0, -9, 0, -9, 0, -9, -3,
    -10, -10, -8, 0, 0, 0, 0, 0,
    0, 0, -3, 0, 0, 0, 0, 0,
    0, 0, -9, 0, 0, 0, -3, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -2, -4, -8, 0,
    0, -8, 0, 0, 0, 0, -4, 0,
    -6, 0, -1, -1, -9, 0, -11, -5,
    -9, 0, -10, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -7, -3,
    0, 0, -5, 0, -3, -6, -5, -6,
    -9, -9, -10, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -3, -2, 0, 0, -4, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -6, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -2,
    -4, -11, 0, 0, 0, 0, -8, -3,
    -11, 0, 0, -9, 0, -10, 0, 0,
    -13, -10, -12, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -11, 0, -18,
    -4, -18, 0, 0, 0, 0, 0, 0,
    0, 0, -14, -13, -15, -9, 0, -14,
    -14, -12, -6, -11, -10, -13, -11, -11,
    -2, 0, -11, 0, 0, 0, -5, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -5, -7, -9, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -9, 0,
    0, 0, -3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -2, -4, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -3,
    0, 0, -7, 0, -5, 0, -9, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -2, -9, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -1, 0, -3, -2, 0,
    0, -3, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -6, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -2, -3, -12, 0, 0,
    0, 0, -8, -4, -13, 0, 0, -10,
    -15, 0, -14, -16, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -14, 0, -6, 0, -27, -2,
    -25, 0, -27, 0, -14, -13, 0, 0,
    0, -12, 0, 0, 0, 0, -15, 0,
    -16, 0, 0, -8, 0, 0, -9, 0,
    -13, -9, -12, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -15,
    0, -12, 0, 0, 0, 0, 0, 0,
    0, -5, -14, -3, -4, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -10,
    -9, 0, -11, -5, -7, 0, -9, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -7, -3, 0, 0, -6, 0,
    -3, -5, -5, -6, -9, -9, -3, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -2, -11, 0,
    0, -8, -4, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -3, 0, 0, 0, 0, 0, 0,
    -3, -6, -2, -3, -5, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -9,
    -9, 0, -12, -9, 0, 0, -3, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -2, -10, 0, 0, 0, -9, 0,
    -9, 0, -9, -2, -11, -10, -8, 0,
    0, -4, 0, 0, 0, 0, -7, 0,
    0, 0, 0, 0, 0, -11, 0, 0,
    -13, -13, -13, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -12, 0, -21,
    -5, -24, 0, 0, 0, 0, 0, 0,
    0, 0, -13, -20, -20, -12, 0, -18,
    -18, -19, -6, -15, -11, -14, -12, -12,
    0, -10, 0, 0, -12, -10, -12, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -8, 0, -18, -3, -21, 0, 0,
    0, 0, 0, 0, 0, 0, -13, -15,
    -17, -5, 0, -10, -11, -11, -2, -9,
    -6, -9, -7, -11, 0, -11, 0, 0,
    -13, -13, -13, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -11, 0, -20,
    -5, -23, 0, 0, 0, 0, 0, 0,
    0, 0, -13, -19, -19, -10, 0, -16,
    -17, -18, -5, -14, -10, -13, -12, -12,
    0, -3, -2, 0, 0, -5, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -5, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -2,
    -4, -10, 0, 0, 0, 0, -7, -4,
    -11, 0, 0, -10, 0, 0, -11, -8,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -10, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -11, -9, -1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -13, 0, -12, -12, -3, 0, -7, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -3, -11, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -11, -10, -9, 0,
    0, 0, 0, 0, 0, 0, -4, 0,
    0, 0, 0, 0, 0, 0, -12, -9,
    0, -4, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -11, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -11, -10, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -6,
    0, 0, -12, -22, -4, 0, -6, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -11, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -11, -10, -8, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -19, -16, -10, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -27, -1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -8,
    0, 0, -11, -8, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -10, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -11, -9, 0, 0,
    0, 0, -1, 0, 0, 0, 0, 0,
    0, 0, 0, -1, -13, 0, -12, -12,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -11, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -11, -10, 0, 0, 0, -5, 0, 0,
    0, 0, -8, 0, -2, 0, 0, 0,
    0, 0, -7, 0, -4, -3, -2, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -3, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -2, -10, 0,
    0, 0, 0, 0, -2, 0, 0, 0,
    0, 0, 0, -3, 0, 0, -10, -2,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -4, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -3, -5, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -3,
    -11, -3, -11, -10, 0, -7, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -10, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -10, -10, 0, -1,
    -4, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -10, 0, 0, -12, -20,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -11, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -11, -10, 0, 0, 0, 0, 0, 0,
    0, 0, -4, 0, 0, 0, 0, 0,
    0, 0, -12, -21, -3, 0, -4, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -4, -11, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -11, -10, -9, 0,
    0, 0, 0, 0, 0, 0, -3, 0,
    0, -1, -2, 0, 0, 0, -13, -8,
    -14, -2, -11, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -12, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -12, -11, -13, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -4,
    0, 0, -12, -10, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -11, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -11, -10, -3, 0,
    0, -6, 0, 0, 0, 0, -7, 0,
    -6, 0, 0, -2, -10, -3, -11, -9,
    0, -6, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -10, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -11, -10, 0, -2, -4, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -9,
    0, 0, -12, -5, -26, -4, -10, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -11, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -11, -10, -11, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -6, 0, 0, -11, -7,
    0, -7, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -10, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -11, -10, 0, -1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -8,
    0, 0, -12, -4, 0, -8, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -10, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -11, -10, 0, -2,
    -2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -9
};


/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes =
{
    .class_pair_values   = kern_class_values,
    .left_class_mapping  = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt      = 47,
    .right_class_cnt     = 44,
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_classes,
    .kern_scale = 16,
    .cmap_num = 2,
    .bpp = 1,
    .kern_classes = 1,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t ui_font_Font16 = {
#else
lv_font_t ui_font_Font16 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 19,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = 0,
    .underline_thickness = 0,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UI_FONT_FONT16*/

