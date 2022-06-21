const express = require('express');
const app = express();
const fs = require('fs');

const port = 1327;

function input(i) {
    return `input_${i}.in`;
}

function output(i) {
    return `out_${i}.out`;
}


function writeScript(num) {
    const green = "\\e[32;1m";
    const red = "\\e[31;1m"
    const greenForegound = "\\e[42;1m"
    const reset = "\\e[0m"

    const printColoredString = function(str, code) {
        return `${code} ${str} ${reset}`;
    }

    const script =
`#!/bin/bash
TEST_CASES=${num}
for (( i=0; i<TEST_CASES; i++ )); do
    ./gtest.o < "input_\${i}.in" > answer_\${i}.ans
    diff -w -y --color=always "answer_\${i}.ans" "out_\${i}.out";
    value="$?"
    if [[ value -eq 0 ]]; then
        echo -e "${printColoredString("PASSED \${i}", green)}"
    else
        echo -e "${printColoredString("FAILED", red)}"
        exit 1
    fi
done
echo -e "Congratulations, ${printColoredString("ACCEPTED", greenForegound)}"
`
    fs.writeFileSync("script.sh", script);
}

app.use(express.json());

app.post('/', (req, res) => {
    const data = req.body;
    const tests = data.tests;
    console.log(`Writing the following Test Cases ${JSON.stringify(tests)}`);
    const len = tests.length;
    for(let i = 0; i < len; ++i) {
        const inp = input(i);
        const out = output(i);
        fs.writeFileSync(inp, tests[i].input, err => {
            console.error(`Error in Writing file ${inp}: ${err}`);
        });
        fs.writeFileSync(out, tests[i].output, err => {
            console.error(`Error in Writing file ${out}: ${err}`);
        });
    }
    res.sendStatus(200);
    writeScript(len);
    process.exit(0);
})

app.listen(port, (err) => {
    if (err) {
        console.error(`Error Occured ${error}`);
        process.exit(1);
    }
    console.log(`Listening to Port ${port}`);
});
