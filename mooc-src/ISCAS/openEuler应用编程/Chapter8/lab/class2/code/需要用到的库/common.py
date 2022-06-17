import os
import re
import random
import string
from collections import namedtuple


# global variables
ngram_size   = 4
context_line = 10
bloomfilter_size = 2097152

PatchInfo = namedtuple('PatchInfo',\
        ['file_path', 'file_all_path','norm_lines', 'hash_list'])
SourceInfo = namedtuple('SourceInfo',\
        ['file_path', 'orig_lines', 'norm_lines'])
ContextInfo = namedtuple('ContextInfo',\
        ['source_id', 'prev_context_line', 'start_line', 'end_line', 'next_context_line'])

# regex for comments
c_regex = re.compile(r'(?P<comment>//.*?$|[{}]+)|(?P<multilinecomment>/\*.*?\*/)|(?P<noncomment>\'(\\.|[^\\\'])*\'|"(\\.|[^\\"])*"|.[^/\'"{}]*)', re.DOTALL | re.MULTILINE)
shellscript_regex = re.compile(r'(?P<comment>#.*?$)|(?P<noncomment>\'(\\.|[^\\\'])*\'|"(\\.|[^\\"])*"|.[^#\'"]*)', re.DOTALL | re.MULTILINE)


# regex for whitespaces except newlines
whitespaces_regex = re.compile(r'[\t\x0b\x0c\r ]+')


def fnv1a_hash(string):
    hash = 2166136261
    for c in string:
        hash ^= ord(c)
        hash *= 16777619
        hash &= 0xFFFFFFFF
    return hash

def djb2_hash(string):
    hash = 5381
    for c in string:
        hash = ((hash << 5) + hash) + ord(c)
        hash &= 0xFFFFFFFF
    return hash

def sdbm_hash(string):
    hash = 0
    for c in string:
        hash = ord(c) + (hash << 6) + (hash << 16) - hash
        hash &= 0xFFFFFFFF
    return hash


