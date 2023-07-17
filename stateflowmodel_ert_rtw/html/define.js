function CodeDefine() { 
this.def = new Array();
this.def["rt_OneStep"] = {file: "ert_main_c.html",line:35,type:"fcn"};
this.def["main"] = {file: "ert_main_c.html",line:72,type:"fcn"};
this.def["rtDW"] = {file: "stateflowmodel_c.html",line:28,type:"var"};
this.def["rtU"] = {file: "stateflowmodel_c.html",line:31,type:"var"};
this.def["rtY"] = {file: "stateflowmodel_c.html",line:34,type:"var"};
this.def["rtM_"] = {file: "stateflowmodel_c.html",line:37,type:"var"};
this.def["rtM"] = {file: "stateflowmodel_c.html",line:38,type:"var"};
this.def["plook_binx"] = {file: "stateflowmodel_c.html",line:52,type:"fcn"};
this.def["binsearch_u32d"] = {file: "stateflowmodel_c.html",line:78,type:"fcn"};
this.def["Cap_table"] = {file: "stateflowmodel_c.html",line:108,type:"fcn"};
this.def["rt_roundd_snf"] = {file: "stateflowmodel_c.html",line:148,type:"fcn"};
this.def["AH_calu1_Init"] = {file: "stateflowmodel_c.html",line:167,type:"fcn"};
this.def["AH_calu1_Enable"] = {file: "stateflowmodel_c.html",line:173,type:"fcn"};
this.def["AH_calu1"] = {file: "stateflowmodel_c.html",line:180,type:"fcn"};
this.def["AH_calu_Init"] = {file: "stateflowmodel_c.html",line:270,type:"fcn"};
this.def["AH_calu"] = {file: "stateflowmodel_c.html",line:276,type:"fcn"};
this.def["stateflowmodel_step"] = {file: "stateflowmodel_c.html",line:352,type:"fcn"};
this.def["stateflowmodel_initialize"] = {file: "stateflowmodel_c.html",line:585,type:"fcn"};
this.def["RT_MODEL"] = {file: "stateflowmodel_h.html",line:36,type:"type"};
this.def["DW_AH_calu1"] = {file: "stateflowmodel_h.html",line:44,type:"type"};
this.def["DW_AH_calu"] = {file: "stateflowmodel_h.html",line:51,type:"type"};
this.def["DW"] = {file: "stateflowmodel_h.html",line:63,type:"type"};
this.def["ConstP"] = {file: "stateflowmodel_h.html",line:108,type:"type"};
this.def["ExtU"] = {file: "stateflowmodel_h.html",line:115,type:"type"};
this.def["ExtY"] = {file: "stateflowmodel_h.html",line:120,type:"type"};
this.def["rtConstP"] = {file: "stateflowmodel_data_c.html",line:21,type:"var"};
this.def["int8_T"] = {file: "rtwtypes_h.html",line:49,type:"type"};
this.def["uint8_T"] = {file: "rtwtypes_h.html",line:50,type:"type"};
this.def["int16_T"] = {file: "rtwtypes_h.html",line:51,type:"type"};
this.def["uint16_T"] = {file: "rtwtypes_h.html",line:52,type:"type"};
this.def["int32_T"] = {file: "rtwtypes_h.html",line:53,type:"type"};
this.def["uint32_T"] = {file: "rtwtypes_h.html",line:54,type:"type"};
this.def["real32_T"] = {file: "rtwtypes_h.html",line:55,type:"type"};
this.def["real64_T"] = {file: "rtwtypes_h.html",line:56,type:"type"};
this.def["real_T"] = {file: "rtwtypes_h.html",line:62,type:"type"};
this.def["time_T"] = {file: "rtwtypes_h.html",line:63,type:"type"};
this.def["boolean_T"] = {file: "rtwtypes_h.html",line:64,type:"type"};
this.def["int_T"] = {file: "rtwtypes_h.html",line:65,type:"type"};
this.def["uint_T"] = {file: "rtwtypes_h.html",line:66,type:"type"};
this.def["ulong_T"] = {file: "rtwtypes_h.html",line:67,type:"type"};
this.def["char_T"] = {file: "rtwtypes_h.html",line:68,type:"type"};
this.def["uchar_T"] = {file: "rtwtypes_h.html",line:69,type:"type"};
this.def["byte_T"] = {file: "rtwtypes_h.html",line:70,type:"type"};
this.def["pointer_T"] = {file: "rtwtypes_h.html",line:88,type:"type"};
}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
var relPathToBuildDir = "../ert_main.c";
var fileSep = "\\";
var isPC = true;
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["ert_main_c.html"] = "../ert_main.c";
	this.html2Root["ert_main_c.html"] = "ert_main_c.html";
	this.html2SrcPath["stateflowmodel_c.html"] = "../stateflowmodel.c";
	this.html2Root["stateflowmodel_c.html"] = "stateflowmodel_c.html";
	this.html2SrcPath["stateflowmodel_h.html"] = "../stateflowmodel.h";
	this.html2Root["stateflowmodel_h.html"] = "stateflowmodel_h.html";
	this.html2SrcPath["stateflowmodel_data_c.html"] = "../stateflowmodel_data.c";
	this.html2Root["stateflowmodel_data_c.html"] = "stateflowmodel_data_c.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "rtwtypes_h.html";
	this.getLink2Src = function (htmlFileName) {
		 if (this.html2SrcPath[htmlFileName])
			 return this.html2SrcPath[htmlFileName];
		 else
			 return null;
	}
	this.getLinkFromRoot = function (htmlFileName) {
		 if (this.html2Root[htmlFileName])
			 return this.html2Root[htmlFileName];
		 else
			 return null;
	}
}
Html2SrcLink.instance = new Html2SrcLink();
var fileList = [
"ert_main_c.html","stateflowmodel_c.html","stateflowmodel_h.html","stateflowmodel_data_c.html","rtwtypes_h.html"];
