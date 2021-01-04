function ckgroupstr(str) {
  const ele = [];
  for (let i in str) {
    if (!ele.includes(str[i])) ele.push(str[i]);
    else {
      if (str[i - 1] !== str[i]) return false;
    }
  }
  return true;
}

const input = [];
require("readline")
  .createInterface(process.stdin, {})
  .on("line", function (line) {
    input.push(line.trim());
  })
  .on("close", function () {
    let res = 0;
    for (var i = 1; i <= +input[0]; i++) if (ckgroupstr(input[i])) res++;
    console.log(res);
  });
