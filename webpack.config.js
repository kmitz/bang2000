const path = require("path");

let config = {
	mode : "development",
	devServer : {
		watchFiles: ["src/*.html"],
		static : ["src"]
	},
	entry: "./src/main.js"

}

module.exports = config;