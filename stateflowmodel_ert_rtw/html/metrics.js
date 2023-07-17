function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["rtDW"] = {file: "D:\\program\\bmsmodel\\bms_soc_simulinkmodel\\充电策略模型\\stateflowmodel_ert_rtw\\stateflowmodel.c",
	size: 71};
	 this.metricsArray.var["rtM_"] = {file: "D:\\program\\bmsmodel\\bms_soc_simulinkmodel\\充电策略模型\\stateflowmodel_ert_rtw\\stateflowmodel.c",
	size: 8};
	 this.metricsArray.var["rtU"] = {file: "D:\\program\\bmsmodel\\bms_soc_simulinkmodel\\充电策略模型\\stateflowmodel_ert_rtw\\stateflowmodel.c",
	size: 24};
	 this.metricsArray.var["rtY"] = {file: "D:\\program\\bmsmodel\\bms_soc_simulinkmodel\\充电策略模型\\stateflowmodel_ert_rtw\\stateflowmodel.c",
	size: 8};
	 this.metricsArray.fcn["AH_calu"] = {file: "D:\\program\\bmsmodel\\bms_soc_simulinkmodel\\充电策略模型\\stateflowmodel_ert_rtw\\stateflowmodel.c",
	stack: 28,
	stackTotal: 44};
	 this.metricsArray.fcn["AH_calu1"] = {file: "D:\\program\\bmsmodel\\bms_soc_simulinkmodel\\充电策略模型\\stateflowmodel_ert_rtw\\stateflowmodel.c",
	stack: 36,
	stackTotal: 52};
	 this.metricsArray.fcn["AH_calu1_Enable"] = {file: "D:\\program\\bmsmodel\\bms_soc_simulinkmodel\\充电策略模型\\stateflowmodel_ert_rtw\\stateflowmodel.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["AH_calu1_Init"] = {file: "D:\\program\\bmsmodel\\bms_soc_simulinkmodel\\充电策略模型\\stateflowmodel_ert_rtw\\stateflowmodel.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["AH_calu_Init"] = {file: "D:\\program\\bmsmodel\\bms_soc_simulinkmodel\\充电策略模型\\stateflowmodel_ert_rtw\\stateflowmodel.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["Cap_table"] = {file: "D:\\program\\bmsmodel\\bms_soc_simulinkmodel\\充电策略模型\\stateflowmodel_ert_rtw\\stateflowmodel.c",
	stack: 5,
	stackTotal: 5};
	 this.metricsArray.fcn["binsearch_u32d"] = {file: "D:\\program\\bmsmodel\\bms_soc_simulinkmodel\\充电策略模型\\stateflowmodel_ert_rtw\\stateflowmodel.c",
	stack: 12,
	stackTotal: 12};
	 this.metricsArray.fcn["ceil"] = {file: "E:\\software\\MATLAB\\R2017a\\sys\\lcc\\include\\math.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["fabs"] = {file: "E:\\software\\MATLAB\\R2017a\\sys\\lcc\\include\\math.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["floor"] = {file: "E:\\software\\MATLAB\\R2017a\\sys\\lcc\\include\\math.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["plook_binx"] = {file: "D:\\program\\bmsmodel\\bms_soc_simulinkmodel\\充电策略模型\\stateflowmodel_ert_rtw\\stateflowmodel.c",
	stack: 4,
	stackTotal: 16};
	 this.metricsArray.fcn["rt_roundd_snf"] = {file: "D:\\program\\bmsmodel\\bms_soc_simulinkmodel\\充电策略模型\\stateflowmodel_ert_rtw\\stateflowmodel.c",
	stack: 8,
	stackTotal: 8};
	 this.metricsArray.fcn["stateflowmodel_initialize"] = {file: "D:\\program\\bmsmodel\\bms_soc_simulinkmodel\\充电策略模型\\stateflowmodel_ert_rtw\\stateflowmodel.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["stateflowmodel_step"] = {file: "D:\\program\\bmsmodel\\bms_soc_simulinkmodel\\充电策略模型\\stateflowmodel_ert_rtw\\stateflowmodel.c",
	stack: 28,
	stackTotal: 80};
	 this.getMetrics = function(token) { 
		 var data;
		 data = this.metricsArray.var[token];
		 if (!data) {
			 data = this.metricsArray.fcn[token];
			 if (data) data.type = "fcn";
		 } else { 
			 data.type = "var";
		 }
	 return data; }; 
	 this.codeMetricsSummary = '<a href="stateflowmodel_metrics.html">Global Memory: 111(bytes) Maximum Stack: 36(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
