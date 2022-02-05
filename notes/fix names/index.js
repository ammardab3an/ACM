import * as fs from 'fs';
const DIR = 'C:\\Users\\AmmarDab3an\\Desktop\\ACM\\problems\\done\\spoj';

fs.readdir(DIR, (err, files) => {

    if(err){
        console.log(err);
        return;
    }
    
    const fixNames = true;
    const fixFolders = false;

    if(fixNames)
    files.forEach(res => {

        if(fs.statSync(`${DIR}\\${res}`).isFile()){

            var new_name = 'spoj - ' + res; //res.replace(/ - .+/, '.cpp');
            if(new_name === res) return;

            fs.rename(`${DIR}\\${res}`, `${DIR}\\${new_name}`, (err) => {
                if(err){
                    console.log(err);
                }
            });
            
            console.log(`${DIR}\\${res}`);
            console.log(`${DIR}\\${new_name}`);
        }
    });

    if(fixFolders)
    files.forEach((res) => {
        if(fs.statSync(`${DIR}\\${res}`).isDirectory() && fs.existsSync(`${DIR}\\${res}\\main.cpp`)){
            
            fs.copyFile(`${DIR}\\${res}\\main.cpp`, `${DIR}\\${res}.cpp`, (err) => {
                if(err){
                    console.log(`cannot copy file: ${res}`);
                }
                else{
                    console.log(`copy succeeded: ${res}`);
                    fs.rm(`${DIR}\\${res}\\main.cpp`, (err) => {
                        if(err){
                            console.log(err);
                        }
                    });
                }
            });
        }
    });
});
