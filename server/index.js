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
    const script =
`#!/bin/bash
source ~/scripts/bash_utils.bash
e_header "Test Cases"
TEST_CASES=${num}
for (( i=0; i<TEST_CASES; i++ )); do
    ./gtest.o < "input_\${i}.in" > answer_\${i}.ans
    colordiff -w -y "answer_\${i}.ans" "out_\${i}.out" | diff-so-fancy;
    diff -w -y "answer_\${i}.ans" "out_\${i}.out"
    value="$?"
    if [[ value -eq 0 ]]; then
        e_success "Passed \${i}"
    else
        e_error "Failed \${i}"
        exit 1
    fi
done
e_success "Congratulations, ACCEPTED"
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
