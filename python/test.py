import tinysvg

# 加载SVG文件
svg = tinysvg.load_svg('input.svg')

# 压缩SVG图片
compressed_svg = svg.encode()

# 保存压缩后的SVG图片到文件
with open('compressed.svg', 'wb') as f:
    f.write(compressed_svg)