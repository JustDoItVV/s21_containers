(this.webpackJsonp=this.webpackJsonp||[]).push([[1035],{"4OTu":function(e,t,s){"use strict";var n=s("cuRJ"),r=s("htOw"),i=s("FV9m"),u=s("JS99"),o=s("Zxcm"),a=s("sEKB"),l=(s("h8Et"),s("uHfJ"),s("R0RX"),s("aZq6")),c=s("xN8+");const d=function(e){let t=arguments.length>1&&void 0!==arguments[1]&&arguments[1];return function(s){return{status:s.status||e,isNew:t,issue:s}}};var p={components:{SmartVirtualList:c.a,ReportItem:l.a},typicalReportItemHeight:32,maxShownReportItems:20,props:{newIssues:{type:Array,required:!1,default:function(){return[]}},unresolvedIssues:{type:Array,required:!1,default:function(){return[]}},resolvedIssues:{type:Array,required:!1,default:function(){return[]}},neutralIssues:{type:Array,required:!1,default:function(){return[]}},component:{type:String,required:!1,default:""},showReportSectionStatusIcon:{type:Boolean,required:!1,default:!0},issuesUlElementClass:{type:String,required:!1,default:""},issueItemClass:{type:String,required:!1,default:null},nestedLevel:{type:Number,required:!1,default:0,validator:function(e){return[0,1,2].includes(e)}}},computed:{issuesWithState(){return[...this.newIssues.map(d(a.g,!0)),...this.unresolvedIssues.map(d(a.g)),...this.neutralIssues.map(d(a.h)),...this.resolvedIssues.map(d(a.i))]},wclass(){return"report-block-list "+this.issuesUlElementClass},listClasses(){return{"gl-pl-9":1===this.nestedLevel,"gl-pl-11-5":2===this.nestedLevel}}}},g=s("bPvS"),m=Object(g.a)(p,(function(){var e=this,t=e.$createElement,s=e._self._c||t;return s("smart-virtual-list",{staticClass:"report-block-container",class:e.listClasses,attrs:{length:e.issuesWithState.length,remain:e.$options.maxShownReportItems,size:e.$options.typicalReportItemHeight,wtag:"ul",wclass:e.wclass}},e._l(e.issuesWithState,(function(t,n){return s("report-item",{key:n,class:e.issueItemClass,attrs:{issue:t.issue,status:t.status,component:e.component,"is-new":t.isNew,"show-report-section-status-icon":e.showReportSectionStatusIcon}})})),1)}),[],!1,null,null,null).exports,h={name:"ReportSection",components:{GlButton:n.a,IssuesList:m,HelpPopover:u.a,StatusIcon:i.a},mixins:[Object(o.a)()],props:{alwaysOpen:{type:Boolean,required:!1,default:!1},component:{type:String,required:!1,default:""},status:{type:String,required:!0},loadingText:{type:String,required:!1,default:""},errorText:{type:String,required:!1,default:""},successText:{type:String,required:!1,default:""},unresolvedIssues:{type:Array,required:!1,default:function(){return[]}},resolvedIssues:{type:Array,required:!1,default:function(){return[]}},neutralIssues:{type:Array,required:!1,default:function(){return[]}},infoText:{type:[String,Boolean],required:!1,default:!1},hasIssues:{type:Boolean,required:!0},popoverOptions:{type:Object,default:function(){return{}},required:!1},showReportSectionStatusIcon:{type:Boolean,required:!1,default:!0},issuesUlElementClass:{type:String,required:!1,default:void 0},issuesListContainerClass:{type:String,required:!1,default:void 0},issueItemClass:{type:String,required:!1,default:void 0},shouldEmitToggleEvent:{type:Boolean,required:!1,default:!1},trackAction:{type:String,required:!1,default:null}},data:()=>({isCollapsed:!0}),computed:{isLoading(){return this.status===a.k.LOADING},loadingFailed(){return this.status===a.k.ERROR},isSuccess(){return this.status===a.k.SUCCESS},isCollapsible(){return!this.alwaysOpen&&this.hasIssues},isExpanded(){return this.alwaysOpen||!this.isCollapsed},statusIconName(){return this.isLoading?"loading":this.loadingFailed||this.unresolvedIssues.length||this.neutralIssues.length?"warning":"success"},headerText(){return this.isLoading?this.loadingText:this.isSuccess?this.successText:this.loadingFailed?this.errorText:""},hasPopover(){return Object.keys(this.popoverOptions).length>0},slotName(){return this.isSuccess?a.f:this.isLoading?a.e:a.d}},methods:{toggleCollapsed(){this.trackAction&&r.b.trackRedisHllUserEvent(this.trackAction),this.shouldEmitToggleEvent&&this.$emit("toggleEvent"),this.isCollapsed=!this.isCollapsed}}},f=Object(g.a)(h,(function(){var e=this,t=e.$createElement,s=e._self._c||t;return s("section",{staticClass:"media-section"},[s("div",{staticClass:"media"},[s("status-icon",{staticClass:"align-self-center",attrs:{status:e.statusIconName,size:24}}),e._v(" "),s("div",{staticClass:"media-body gl-display-flex gl-align-items-flex-start gl-flex-direction-row!"},[s("div",{staticClass:"js-code-text code-text gl-align-self-center gl-flex-grow-1",attrs:{"data-testid":"report-section-code-text"}},[s("div",{staticClass:"gl-display-flex gl-align-items-center"},[s("p",{staticClass:"gl-line-height-normal gl-m-0"},[e._v(e._s(e.headerText))]),e._v(" "),e._t(e.slotName),e._v(" "),e.hasPopover?s("help-popover",{staticClass:"gl-ml-2 gl-display-inline-flex",attrs:{options:e.popoverOptions}}):e._e()],2),e._v(" "),e._t("sub-heading")],2),e._v(" "),e._t("action-buttons",null,{isCollapsible:e.isCollapsible}),e._v(" "),e.isCollapsible?s("div",{staticClass:"gl-border-l-1 gl-border-l-solid gl-border-gray-100 gl-ml-3 gl-pl-3"},[s("gl-button",{attrs:{"data-testid":"report-section-expand-button","data-qa-selector":"expand_report_button",category:"tertiary",size:"small",icon:e.isExpanded?"chevron-lg-up":"chevron-lg-down"},on:{click:e.toggleCollapsed}})],1):e._e()],2)],1),e._v(" "),e.hasIssues?s("div",{directives:[{name:"show",rawName:"v-show",value:e.isExpanded,expression:"isExpanded"}],staticClass:"js-report-section-container"},[e._t("body",(function(){return[s("issues-list",{class:e.issuesListContainerClass,attrs:{"unresolved-issues":e.unresolvedIssues,"resolved-issues":e.resolvedIssues,"neutral-issues":e.neutralIssues,component:e.component,"show-report-section-status-icon":e.showReportSectionStatusIcon,"issues-ul-element-class":e.issuesUlElementClass,"issue-item-class":e.issueItemClass}})]}))],2):e._e()])}),[],!1,null,null,null);t.a=f.exports},JS99:function(e,t,s){"use strict";var n=s("cuRJ"),r=s("KFH7"),i=s("JmT7"),u={name:"HelpPopover",components:{GlButton:n.a,GlPopover:r.a},directives:{SafeHtml:i.a},props:{options:{type:Object,required:!1,default:function(){return{}}},icon:{type:String,required:!1,default:"question-o"}},methods:{targetFn(){var e;return null===(e=this.$refs.popoverTrigger)||void 0===e?void 0:e.$el}}},o=s("bPvS"),a=Object(o.a)(u,(function(){var e=this,t=e.$createElement,s=e._self._c||t;return s("span",[s("gl-button",{ref:"popoverTrigger",attrs:{variant:"link",icon:e.icon,"aria-label":e.__("Help")}}),e._v(" "),s("gl-popover",e._b({attrs:{target:e.targetFn},scopedSlots:e._u([e.options.title?{key:"title",fn:function(){return[s("span",{directives:[{name:"safe-html",rawName:"v-safe-html",value:e.options.title,expression:"options.title"}]})]},proxy:!0}:null,{key:"default",fn:function(){return[s("div",{directives:[{name:"safe-html",rawName:"v-safe-html",value:e.options.content,expression:"options.content"}]})]},proxy:!0},e._l(Object.keys(e.$slots),(function(t){return{key:t,fn:function(){return[e._t(t)]},proxy:!0}}))],null,!0)},"gl-popover",e.options,!1))],1)}),[],!1,null,null,null);t.a=a.exports},aZq6:function(e,t,s){"use strict";s("h8Et");var n=s("w1SK"),r={name:"ReportItem",components:{...n.b,...n.d},props:{issue:{type:Object,required:!0},component:{type:String,required:!1,default:"",validator:function(e){return""===e||Object.values(n.a).includes(e)}},iconComponent:{type:String,required:!1,default:n.c.IssueStatusIcon,validator:function(e){return Object.values(n.c).includes(e)}},status:{type:String,required:!0},statusIconSize:{type:Number,required:!1,default:24},isNew:{type:Boolean,required:!1,default:!1},showReportSectionStatusIcon:{type:Boolean,required:!1,default:!0}}},i=s("bPvS"),u=Object(i.a)(r,(function(){var e=this,t=e.$createElement,s=e._self._c||t;return s("li",{staticClass:"report-block-list-issue align-items-center",attrs:{"data-qa-selector":"report_item_row"}},[e.showReportSectionStatusIcon?s(e.iconComponent,{tag:"component",staticClass:"gl-mr-2",attrs:{status:e.status,"status-icon-size":e.statusIconSize}}):e._e(),e._v(" "),e.component?s(e.component,{tag:"component",attrs:{issue:e.issue,status:e.status,"is-new":e.isNew}}):e._e()],1)}),[],!1,null,null,null);t.a=u.exports},bTFz:function(e,t,s){"use strict";var n=s("H8gz"),r=s("sEKB"),i={name:"LicenseStatusIcon",components:{GlIcon:n.a},props:{status:{type:String,required:!0},statusIconSize:{type:Number,required:!1,default:12}},computed:{iconName(){return this.isStatusFailed?"status-failed":this.isStatusSuccess?"status-success":"status-alert"},isStatusFailed(){return this.status===r.g},isStatusSuccess(){return this.status===r.i},isStatusNeutral(){return this.status===r.h}}},u=s("bPvS"),o=Object(u.a)(i,(function(){var e=this.$createElement,t=this._self._c||e;return t("div",{staticClass:"report-block-list-icon",class:{failed:this.isStatusFailed,success:this.isStatusSuccess,neutral:this.isStatusNeutral}},[t("gl-icon",{staticClass:"gl-mb-1",attrs:{name:this.iconName,size:this.statusIconSize,"data-qa-selector":"status_"+this.status+"_icon"}})],1)}),[],!1,null,null,null);t.a=o.exports},dwKt:function(e,t,s){"use strict";var n=s("H8gz"),r=s("sEKB"),i={name:"IssueStatusIcon",components:{GlIcon:n.a},props:{status:{type:String,required:!0},statusIconSize:{type:Number,required:!1,default:24}},computed:{iconName(){return this.isStatusFailed?"status_failed_borderless":this.isStatusSuccess?"status_success_borderless":"dash"},isStatusFailed(){return this.status===r.g},isStatusSuccess(){return this.status===r.i},isStatusNeutral(){return this.status===r.h}}},u=s("bPvS"),o=Object(u.a)(i,(function(){var e=this.$createElement,t=this._self._c||e;return t("div",{staticClass:"report-block-list-icon",class:{failed:this.isStatusFailed,success:this.isStatusSuccess,neutral:this.isStatusNeutral}},[t("gl-icon",{attrs:{name:this.iconName,size:this.statusIconSize,"data-qa-selector":"status_"+this.status+"_icon"}})],1)}),[],!1,null,null,null);t.a=o.exports},o21G:function(e,t,s){"use strict";s.r(t);s("0no1"),s("3R5X"),s("gdbl"),s("ujLG"),s("HaUQ");var n=s("nPFI"),r=s("w1SK"),i=s("t9l/"),u=s("4OTu"),o=s("sEKB"),a={name:"BlockingMergeRequestsReport",components:{ReportSection:u.a,GlSprintf:n.a},props:{mr:{type:Object,required:!0}},computed:{blockingMergeRequests(){return this.mr.blockingMergeRequests||{}},visibleMergeRequests(){return this.blockingMergeRequests.visible_merge_requests||{}},shouldRenderBlockingMergeRequests(){return this.blockingMergeRequests.total_count>0},openBlockingMergeRequests(){return this.visibleMergeRequests.opened||[]},closedBlockingMergeRequests(){return this.visibleMergeRequests.closed||[]},mergedBlockingMergeRequests(){return this.visibleMergeRequests.merged||[]},unmergedBlockingMergeRequests(){var e=this;return Object.keys(this.visibleMergeRequests).filter((function(e){return"merged"!==e})).reduce((function(t,s){return"closed"===s?[...e.visibleMergeRequests[s],...t]:[...t,...e.visibleMergeRequests[s]]}),[])},unresolvedIssues(){return this.blockingMergeRequests.hidden_count>0?[{hiddenCount:this.blockingMergeRequests.hidden_count},...this.unmergedBlockingMergeRequests]:this.unmergedBlockingMergeRequests},isBlocked(){return this.blockingMergeRequests.hidden_count>0||this.unmergedBlockingMergeRequests.length>0},closedCount(){return this.closedBlockingMergeRequests.length},unmergedCount(){return this.unmergedBlockingMergeRequests.length+this.blockingMergeRequests.hidden_count},blockedByText(){if(this.closedCount>0&&this.closedCount===this.unmergedCount)return Object(i.h)(Object(i.f)("Depends on %{strongStart}%{closedCount} closed%{strongEnd} merge request.","Depends on %{strongStart}%{closedCount} closed%{strongEnd} merge requests.",this.closedCount),{closedCount:this.closedCount});const e=Object(i.f)("Depends on %d merge request being merged","Depends on %d merge requests being merged",this.unmergedCount);return this.closedCount>0?`${e} %{strongStart}${Object(i.f)("(%d closed)","(%d closed)",this.closedCount)}%{strongEnd}`:e},status(){return this.isBlocked?o.k.ERROR:o.k.SUCCESS}},componentNames:r.a},l=s("bPvS"),c=Object(l.a)(a,(function(){var e=this,t=e.$createElement,s=e._self._c||t;return e.shouldRenderBlockingMergeRequests?s("report-section",{staticClass:"mr-widget-border-top mr-report blocking-mrs-report",attrs:{status:e.status,"has-issues":!0,"unresolved-issues":e.unresolvedIssues,"resolved-issues":e.mergedBlockingMergeRequests,component:e.$options.componentNames.BlockingMergeRequestsBody,"show-report-section-status-icon":!1,"issues-ul-element-class":"content-list","issues-list-container-class":"p-0","issue-item-class":"p-0"},scopedSlots:e._u([{key:"success",fn:function(){return[e._v("\n    "+e._s(e.__("All merge request dependencies have been merged"))+"\n    "),s("span",{staticClass:"text-secondary gl-ml-1"},[e._v("\n      "+e._s(e.sprintf(e.__("(%{mrCount} merged)"),{mrCount:e.blockingMergeRequests.total_count-e.unmergedBlockingMergeRequests.length}))+"\n    ")])]},proxy:!0},{key:"error",fn:function(){return[s("span",[s("gl-sprintf",{attrs:{message:e.blockedByText},scopedSlots:e._u([{key:"strong",fn:function(t){var n=t.content;return[s("strong",[e._v(e._s(n))])]}}],null,!1,3347598221)})],1)]},proxy:!0}],null,!1,3055307072)}):e._e()}),[],!1,null,null,null);t.default=c.exports},w1SK:function(e,t,s){"use strict";s.d(t,"b",(function(){return a})),s.d(t,"a",(function(){return l})),s.d(t,"d",(function(){return c})),s.d(t,"c",(function(){return d}));var n=s("bTFz"),r=s("dwKt");const i={CodequalityIssueBody:function(){return s.e(1094).then(s.bind(null,"yUcO"))}},u={IssueStatusIcon:r.a},o={IssueStatusIcon:r.a.name},a={...i,PerformanceIssueBody:function(){return s.e(1064).then(s.bind(null,"eLOp"))},LicenseIssueBody:function(){return s.e(1068).then(s.bind(null,"Qgsm"))},SecurityIssueBody:function(){return s.e(1039).then(s.bind(null,"vW1a"))},MetricsReportsIssueBody:function(){return s.e(1238).then(s.bind(null,"mhbl"))},BlockingMergeRequestsBody:function(){return Promise.all([s.e(102),s.e(1036)]).then(s.bind(null,"KL8m"))}},l={CodequalityIssueBody:"CodequalityIssueBody",PerformanceIssueBody:"PerformanceIssueBody",LicenseIssueBody:"LicenseIssueBody",SecurityIssueBody:"SecurityIssueBody",MetricsReportsIssueBody:"MetricsReportsIssueBody",BlockingMergeRequestsBody:"BlockingMergeRequestsBody"},c={...u,LicenseStatusIcon:n.a},d={...o,LicenseStatusIcon:n.a.name}},"xN8+":function(e,t,s){"use strict";var n=s("nQy4"),r={name:"SmartVirtualList",components:{VirtualList:s.n(n).a},props:{size:{type:Number,required:!0},length:{type:Number,required:!0},remain:{type:Number,required:!0},rtag:{type:String,default:"div",required:!1},wtag:{type:String,default:"div",required:!1},wclass:{type:String,default:null,required:!1}}},i=s("bPvS"),u=Object(i.a)(r,(function(){var e=this,t=e.$createElement,s=e._self._c||t;return e.length>e.remain?s("virtual-list",e._b({staticClass:"js-virtual-list",attrs:{size:e.remain,remain:e.remain,rtag:e.rtag,wtag:e.wtag,wclass:e.wclass}},"virtual-list",e.$attrs,!1),[e._t("default")],2):s(e.rtag,{tag:"component",staticClass:"js-plain-element"},[s(e.wtag,{tag:"component",class:e.wclass},[e._t("default")],2)],1)}),[],!1,null,null,null);t.a=u.exports}}]);
//# sourceMappingURL=1035.ebcf7999.chunk.js.map