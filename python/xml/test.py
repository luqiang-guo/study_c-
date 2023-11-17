import csv
import xml.etree.ElementTree as ET
import xml.dom.minidom as minidom

def dict_to_xml(tag, d):
    """
    Turn a simple dict of key/value pairs into XML
    """
    elem = ET.Element(tag)
    for key, val in d.items():
        child = ET.Element(key)
        child.text = str(val)
        elem.append(child)
    return elem

def list_to_xml(tag, l):
    """
    Turn a list of dictionaries into XML
    """
    root = ET.Element(tag)
    for d in l:
        root.append(dict_to_xml('WORD0', d))
    return ET.tostring(root)

# # 示例数据
# data = [
#     {'name': 'Alice', 'age': 25},
#     {'name': 'Bob', 'age': 30},
#     {'name': 'Charlie', 'age': 35}
# ]

data = [
    {'format': 'scalar instr name', 'age': 'imm'},
    {'format': 'nop',               'age': '0'}]
# 转换为XML格式
xml_data = list_to_xml('ROOT', data)


# 输出结果
print(xml_data.decode())

with open('data.xml', 'wb') as file:
    file.write(xml_data)

dom = minidom.parseString(xml_data)
print(dom.toprettyxml())



# def main():
#     xml_lsit = []
#     with open('simd.csv', newline='') as csvfile:
#         xml_lsit = list(csv.DictReader(csvfile))

#     print(xml_lsit)

#     xml_data = list_to_xml("ROOT", xml_lsit)

#     dom = minidom.parseString(xml_data)
#     print(dom.toprettyxml())


# if __name__ == "__main__":
#     main()