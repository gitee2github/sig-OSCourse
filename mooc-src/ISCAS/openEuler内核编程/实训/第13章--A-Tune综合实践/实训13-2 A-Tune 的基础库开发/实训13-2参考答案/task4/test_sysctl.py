#!/usr/bin/python3
# -*- coding: utf-8 -*-
# Copyright (c) 2019 Huawei Technologies Co., Ltd.
# A-Tune is licensed under the Mulan PSL v2.
# You can use this software according to the terms and conditions of the Mulan PSL v2.
# You may obtain a copy of Mulan PSL v2 at:
#     http://license.coscl.org.cn/MulanPSL2
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR
# PURPOSE.
# See the Mulan PSL v2 for more details.
# Create: 2019-10-29

"""
Test case.
"""
from atune_collector.plugin.configurator.sysctl.sysctl import Sysctl


class TestSysctl:
    """ test sysctl"""
    user = "UT"
    key = "kernel.randomize_va_space"

    def test_get_sysctl(self):
        """test get sysctl"""
        sysctl = Sysctl(self.user)
        value = sysctl.get(self.key)
        print("get done, value={}".format(value))

    def test_set_sysctl(self,v):
        """test set sysctl"""
        sysctl = Sysctl(self.user)
        value = sysctl.set("{}={}".format(self.key, v))
        print("set done")

if __name__ == "__main__":
    test = TestSysctl()
    test.test_get_sysctl()
    test.test_set_sysctl(2)
    test.test_get_sysctl()
~                    
