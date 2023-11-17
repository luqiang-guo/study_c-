import os
import csv

import xml.etree.ElementTree as ET

def dict_to_xml(tag, d):
    """
    将字典转换成 XML 元素
    :param tag: 元素名称
    :param d: 字典数据
    :return: XML 元素对象
    """
    elem = ET.Element(tag)
    for key, val in d.items():
        child_elem = ET.Element(key)
        child_elem.text = str(val)
        elem.append(child_elem)
    return elem

def main():
    xml_lsit = []
    with open('simd.csv', newline='') as csvfile:
        xml_lsit = list(csv.DictReader(csvfile))

    print(xml_lsit)

    for line in xml_lsit :
        elem = dict_to_xml( line['format'], line)
        tmp = {}
        
        print(ET.tostring(elem, encoding='utf8').decode())
        

if __name__ == "__main__":
    main()