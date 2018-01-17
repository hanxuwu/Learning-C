# Vscode User Setting

![image](https://github.com/hanxuwu/Learning-C/blob/master/Environment-Config/Vscode/VscodeUserSetting/SCREENSHOT/extension_1.PNG)

![image](https://github.com/hanxuwu/Learning-C/blob/master/Environment-Config/Vscode/VscodeUserSetting/SCREENSHOT/extension_2.PNG)

![image](https://github.com/hanxuwu/Learning-C/blob/master/Environment-Config/Vscode/VscodeUserSetting/SCREENSHOT/extension_3.PNG)

![image](https://github.com/hanxuwu/Learning-C/blob/master/Environment-Config/Vscode/VscodeUserSetting/SCREENSHOT/extension_4.PNG)


## How to download the extension for offline installation  

A VS Code extension's offline install package (VSIX) is   available at:  
 
https://${publisher}.gallery.vsassets.io/_apis/public/gallery/publisher/${publisher}/extension/${extension name}/${version}/assetbyname/Microsoft.VisualStudio.Services.VSIXPackage  

Take the syntax highlight extension for Vue.js as an example:  

https://marketplace.visualstudio.com/items?itemName=liuji-jim.vue  

The itemName query is a composition of publisher and extension name, separated with a dot.  
The publisher is liuji-jim.  
The extension name is vue.  
The latest version number is in More Info section on the right side.  
more  
So the package can be downloaded via this URL:  

https://liuji-jim.gallery.vsassets.io/_apis/public/gallery/publisher/liuji-jim/extension/vue/0.1.3/assetbyname/Microsoft.VisualStudio.Services.VSIXPackage  

Then modify it to .vsix  
install from Vscode