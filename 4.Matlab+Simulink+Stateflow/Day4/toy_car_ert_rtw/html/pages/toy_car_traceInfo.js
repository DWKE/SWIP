function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "toy_car"};
	this.sidHashMap["toy_car"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "toy_car:1"};
	this.sidHashMap["toy_car:1"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S2>"] = {sid: "toy_car:13"};
	this.sidHashMap["toy_car:13"] = {rtwname: "<S2>"};
	this.rtwnameHashMap["<S3>"] = {sid: "toy_car:9"};
	this.sidHashMap["toy_car:9"] = {rtwname: "<S3>"};
	this.rtwnameHashMap["<S4>"] = {sid: "toy_car:4"};
	this.sidHashMap["toy_car:4"] = {rtwname: "<S4>"};
	this.rtwnameHashMap["<Root>/Chart"] = {sid: "toy_car:1"};
	this.sidHashMap["toy_car:1"] = {rtwname: "<Root>/Chart"};
	this.rtwnameHashMap["<Root>/DIR"] = {sid: "toy_car:13"};
	this.sidHashMap["toy_car:13"] = {rtwname: "<Root>/DIR"};
	this.rtwnameHashMap["<Root>/Display"] = {sid: "toy_car:2"};
	this.sidHashMap["toy_car:2"] = {rtwname: "<Root>/Display"};
	this.rtwnameHashMap["<Root>/Mux"] = {sid: "toy_car:3"};
	this.sidHashMap["toy_car:3"] = {rtwname: "<Root>/Mux"};
	this.rtwnameHashMap["<Root>/Mux1"] = {sid: "toy_car:8"};
	this.sidHashMap["toy_car:8"] = {rtwname: "<Root>/Mux1"};
	this.rtwnameHashMap["<Root>/SPD"] = {sid: "toy_car:9"};
	this.sidHashMap["toy_car:9"] = {rtwname: "<Root>/SPD"};
	this.rtwnameHashMap["<Root>/SW"] = {sid: "toy_car:4"};
	this.sidHashMap["toy_car:4"] = {rtwname: "<Root>/SW"};
	this.rtwnameHashMap["<S1>:1"] = {sid: "toy_car:1:1"};
	this.sidHashMap["toy_car:1:1"] = {rtwname: "<S1>:1"};
	this.rtwnameHashMap["<S1>:3"] = {sid: "toy_car:1:3"};
	this.sidHashMap["toy_car:1:3"] = {rtwname: "<S1>:3"};
	this.rtwnameHashMap["<S1>:18"] = {sid: "toy_car:1:18"};
	this.sidHashMap["toy_car:1:18"] = {rtwname: "<S1>:18"};
	this.rtwnameHashMap["<S1>:5"] = {sid: "toy_car:1:5"};
	this.sidHashMap["toy_car:1:5"] = {rtwname: "<S1>:5"};
	this.rtwnameHashMap["<S1>:4"] = {sid: "toy_car:1:4"};
	this.sidHashMap["toy_car:1:4"] = {rtwname: "<S1>:4"};
	this.rtwnameHashMap["<S1>:23"] = {sid: "toy_car:1:23"};
	this.sidHashMap["toy_car:1:23"] = {rtwname: "<S1>:23"};
	this.rtwnameHashMap["<S1>:25"] = {sid: "toy_car:1:25"};
	this.sidHashMap["toy_car:1:25"] = {rtwname: "<S1>:25"};
	this.rtwnameHashMap["<S1>:27"] = {sid: "toy_car:1:27"};
	this.sidHashMap["toy_car:1:27"] = {rtwname: "<S1>:27"};
	this.rtwnameHashMap["<S1>:2"] = {sid: "toy_car:1:2"};
	this.sidHashMap["toy_car:1:2"] = {rtwname: "<S1>:2"};
	this.rtwnameHashMap["<S1>:6"] = {sid: "toy_car:1:6"};
	this.sidHashMap["toy_car:1:6"] = {rtwname: "<S1>:6"};
	this.rtwnameHashMap["<S1>:7"] = {sid: "toy_car:1:7"};
	this.sidHashMap["toy_car:1:7"] = {rtwname: "<S1>:7"};
	this.rtwnameHashMap["<S1>:11"] = {sid: "toy_car:1:11"};
	this.sidHashMap["toy_car:1:11"] = {rtwname: "<S1>:11"};
	this.rtwnameHashMap["<S1>:9"] = {sid: "toy_car:1:9"};
	this.sidHashMap["toy_car:1:9"] = {rtwname: "<S1>:9"};
	this.rtwnameHashMap["<S1>:10"] = {sid: "toy_car:1:10"};
	this.sidHashMap["toy_car:1:10"] = {rtwname: "<S1>:10"};
	this.rtwnameHashMap["<S1>:24"] = {sid: "toy_car:1:24"};
	this.sidHashMap["toy_car:1:24"] = {rtwname: "<S1>:24"};
	this.rtwnameHashMap["<S1>:22"] = {sid: "toy_car:1:22"};
	this.sidHashMap["toy_car:1:22"] = {rtwname: "<S1>:22"};
	this.rtwnameHashMap["<S1>:26"] = {sid: "toy_car:1:26"};
	this.sidHashMap["toy_car:1:26"] = {rtwname: "<S1>:26"};
	this.rtwnameHashMap["<S2>/Constant"] = {sid: "toy_car:14"};
	this.sidHashMap["toy_car:14"] = {rtwname: "<S2>/Constant"};
	this.rtwnameHashMap["<S2>/Data Type Conversion"] = {sid: "toy_car:15"};
	this.sidHashMap["toy_car:15"] = {rtwname: "<S2>/Data Type Conversion"};
	this.rtwnameHashMap["<S2>/Out1"] = {sid: "toy_car:16"};
	this.sidHashMap["toy_car:16"] = {rtwname: "<S2>/Out1"};
	this.rtwnameHashMap["<S3>/Constant"] = {sid: "toy_car:10"};
	this.sidHashMap["toy_car:10"] = {rtwname: "<S3>/Constant"};
	this.rtwnameHashMap["<S3>/Data Type Conversion"] = {sid: "toy_car:11"};
	this.sidHashMap["toy_car:11"] = {rtwname: "<S3>/Data Type Conversion"};
	this.rtwnameHashMap["<S3>/Out1"] = {sid: "toy_car:12"};
	this.sidHashMap["toy_car:12"] = {rtwname: "<S3>/Out1"};
	this.rtwnameHashMap["<S4>/Constant"] = {sid: "toy_car:5"};
	this.sidHashMap["toy_car:5"] = {rtwname: "<S4>/Constant"};
	this.rtwnameHashMap["<S4>/Data Type Conversion"] = {sid: "toy_car:6"};
	this.sidHashMap["toy_car:6"] = {rtwname: "<S4>/Data Type Conversion"};
	this.rtwnameHashMap["<S4>/Out1"] = {sid: "toy_car:7"};
	this.sidHashMap["toy_car:7"] = {rtwname: "<S4>/Out1"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
