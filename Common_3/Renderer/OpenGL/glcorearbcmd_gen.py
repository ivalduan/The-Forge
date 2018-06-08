import glob
import os
import sys

def getFileLines(filepath):
    basecontent = ""
    with open(filepath, 'r' ) as infile:
        basecontent = infile.read()
        infile.close()
    lines = basecontent.splitlines()
    return lines


def getApiLines(lines):
    apilines = []
    for line in lines:
        if line.startswith('GLAPI'):
            apilines.append(line)
    return apilines


def processApiLineName(line):
    name = line.split()[3]
    if name.startswith("gl"):
        return name
    name = line.split()[4]
    if name.startswith("gl"):
        return name
    name = line.split()[5]
    if name.startswith("gl"):
        return name
    #print(name)
    return name

def processApiLineParams(line):
    paramtoks = line[line.find('(')+1:line.find(')')].split(',')
    params = []
    for paramtok in paramtoks:
        namefirst = 0
        if '*' in paramtok:
            namefirst = paramtok.rfind('*') + 1
        elif ' ' in paramtok:
            namefirst = paramtok.rfind(' ') + 1

        if namefirst > 0:
            param = {'type':paramtok[:namefirst].strip(), 'name':paramtok[namefirst:]}
            #print('%s||||%s'% (param['type'], param['name']))
            params.append(param)

    return params

def processApi(lines):
    api = []
    for line in lines:
        apientry = {'fn':processApiLineName(line), 'params':processApiLineParams(line)}

        api.append(apientry)
    return api


def processApiCmd(api):
    for apientry in api:
        ename = "GL_STRUCTURE_TYPE_COMMAND_" + apientry['fn'][2:];
        mname = "m" + apientry['fn'][2:];
        sname = "GlCmd" + apientry['fn'][2:];
        #print(sname)
        apientry['ename'] = ename
        apientry['mname'] = mname
        apientry['sname'] = sname
        for par in apientry['params']:
            par['mname'] = "m" + par['name'].title()


def strApiCmdDefinition(apientry):
    s = ''
    s += 'struct {0} {{\n'.format(apientry['sname'])
    s += '\tGlCmdType sType;\n'
    for par in apientry['params']:
        s += '\t{0} {1};\n'.format(par['type'], par['mname'])
    s += '};\n'
    #print(s)
    return s

def strApiCmdEnum(api):
    s = ''
    s += 'enum GlCmdType {\n'
    s += '\tGL_STRUCTURE_TYPE_COMMAND_Undefined = 0,\n'
    for apientry in api:
        s += '\t{0},\n'.format(apientry['ename'])
    s += '};\n'
    return s

def strApiCmdUnion(api):
    s = ''
    s += 'struct GlCmd {\n'
    s += '\tunion {\n'
    for apientry in api:
        s += '\t\t{0} {1};\n'.format(apientry['sname'], apientry['mname'])
    s += '\t};\n'
    s += '};\n'
    #print(s)
    return s

def strApiCmdListSubmitv(api):
    s = ''
    s += 'inline void glCmdSubmitv(GlCmd* pCmd, size_t n) {\n'
    s += '\tGlCmd* pCmdLast = pCmd + n;\n'
    s += '\tfor (; pCmd != pCmdLast; ++pCmd) {\n'
    s += '\t\tGlCmdType sType = *(GlCmdType *)pCmd;\n'
    s += '\t\tswitch (sType) {\n'
    for apientry in api:
        s += '\t\tcase {0}: {{\n'.format(apientry['ename'])
        s += '\t\t\t{0}* pCC = ({0}*)pCmd;\n'.format(apientry['sname'])
        s += '\t\t\t{0}('.format(apientry['fn'])
        params = apientry['params']
        pn = len(params)
        for pi in range(pn):
            s += 'pCC->{0}'.format(params[pi]['mname'])
            if pi < pn-1:
                s += ', '
        s += ');\n'.format(apientry['fn'])
        s += '\t\t} break;\n'
    s += '\t\t}\n'
    s += '\t}\n'
    s += '}\n'
    return s


def strCopyright():
    s = ''
    s += '/*\n'
    s += ' * Copyright (c) 2018 Next Limit S.L.\n'
    s += ' *\n'
    s += ' * Licensed to the Apache Software Foundation (ASF) under one\n'
    s += ' * or more contributor license agreements.  See the NOTICE file\n'
    s += ' * distributed with this work for additional information\n'
    s += ' * regarding copyright ownership.  The ASF licenses this file\n'
    s += ' * to you under the Apache License, Version 2.0 (the\n'
    s += ' * "License"); you may not use this file except in compliance\n'
    s += ' * with the License.  You may obtain a copy of the License at\n'
    s += ' *\n'
    s += ' *   http://www.apache.org/licenses/LICENSE-2.0\n'
    s += ' *\n'
    s += ' * Unless required by applicable law or agreed to in writing,\n'
    s += ' * software distributed under the License is distributed on an\n'
    s += ' * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY\n'
    s += ' * KIND, either express or implied.  See the License for the\n'
    s += ' * specific language governing permissions and limitations\n'
    s += ' * under the License.\n'
    s += '*/\n'
    return s


def processFile_glcorearb():
    filepath = "glcorearb.h"

    filelines = getFileLines(filepath)

    apilines = getApiLines(filelines)

    api = processApi(apilines)

    processApiCmd(api)

    scopyright = strCopyright()

    senum = strApiCmdEnum(api)
    #print(senum)

    stypes = ""
    for apientry in api:
        stype = strApiCmdDefinition(apientry)
        #print(stype)
        stypes += stype + '\n'

    sunion = strApiCmdUnion(api)

    ssubmit = strApiCmdListSubmitv(api)

    filepathout = "glcorearbcmd.h"

    with open(filepathout, 'w' ) as outfile:
        outfile.write(scopyright)
        outfile.write('\n')
        outfile.write(senum)
        outfile.write('\n')
        outfile.write(stypes)
        outfile.write('\n')
        outfile.write(sunion)
        outfile.write('\n')
        outfile.write(ssubmit)
        outfile.close()

if __name__ == "__main__":
    processFile_glcorearb()
