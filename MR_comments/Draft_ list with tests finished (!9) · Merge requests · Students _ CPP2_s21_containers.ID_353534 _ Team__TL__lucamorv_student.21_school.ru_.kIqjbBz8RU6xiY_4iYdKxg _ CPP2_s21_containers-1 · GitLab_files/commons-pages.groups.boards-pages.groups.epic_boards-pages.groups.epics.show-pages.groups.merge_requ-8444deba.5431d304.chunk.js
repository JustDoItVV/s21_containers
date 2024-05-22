(this.webpackJsonp=this.webpackJsonp||[]).push([[22],{"2UZr":function(e,n,i){var t={kind:"Document",definitions:[{kind:"OperationDefinition",operation:"query",name:{kind:"Name",value:"workItemNotesByIid"},variableDefinitions:[{kind:"VariableDefinition",variable:{kind:"Variable",name:{kind:"Name",value:"fullPath"}},type:{kind:"NonNullType",type:{kind:"NamedType",name:{kind:"Name",value:"ID"}}},directives:[]},{kind:"VariableDefinition",variable:{kind:"Variable",name:{kind:"Name",value:"iid"}},type:{kind:"NamedType",name:{kind:"Name",value:"String"}},directives:[]},{kind:"VariableDefinition",variable:{kind:"Variable",name:{kind:"Name",value:"after"}},type:{kind:"NamedType",name:{kind:"Name",value:"String"}},directives:[]},{kind:"VariableDefinition",variable:{kind:"Variable",name:{kind:"Name",value:"pageSize"}},type:{kind:"NamedType",name:{kind:"Name",value:"Int"}},directives:[]}],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"Field",alias:{kind:"Name",value:"workspace"},name:{kind:"Name",value:"project"},arguments:[{kind:"Argument",name:{kind:"Name",value:"fullPath"},value:{kind:"Variable",name:{kind:"Name",value:"fullPath"}}}],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"Field",name:{kind:"Name",value:"id"},arguments:[],directives:[]},{kind:"Field",name:{kind:"Name",value:"workItems"},arguments:[{kind:"Argument",name:{kind:"Name",value:"iid"},value:{kind:"Variable",name:{kind:"Name",value:"iid"}}}],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"Field",name:{kind:"Name",value:"nodes"},arguments:[],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"Field",name:{kind:"Name",value:"id"},arguments:[],directives:[]},{kind:"Field",name:{kind:"Name",value:"iid"},arguments:[],directives:[]},{kind:"Field",name:{kind:"Name",value:"widgets"},arguments:[],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"InlineFragment",typeCondition:{kind:"NamedType",name:{kind:"Name",value:"WorkItemWidgetNotes"}},directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"Field",name:{kind:"Name",value:"type"},arguments:[],directives:[]},{kind:"Field",name:{kind:"Name",value:"discussions"},arguments:[{kind:"Argument",name:{kind:"Name",value:"first"},value:{kind:"Variable",name:{kind:"Name",value:"pageSize"}}},{kind:"Argument",name:{kind:"Name",value:"after"},value:{kind:"Variable",name:{kind:"Name",value:"after"}}},{kind:"Argument",name:{kind:"Name",value:"filter"},value:{kind:"EnumValue",value:"ALL_NOTES"}}],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"Field",name:{kind:"Name",value:"pageInfo"},arguments:[],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"FragmentSpread",name:{kind:"Name",value:"PageInfo"},directives:[]}]}},{kind:"Field",name:{kind:"Name",value:"nodes"},arguments:[],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"Field",name:{kind:"Name",value:"id"},arguments:[],directives:[]},{kind:"Field",name:{kind:"Name",value:"notes"},arguments:[],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"Field",name:{kind:"Name",value:"nodes"},arguments:[],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"FragmentSpread",name:{kind:"Name",value:"WorkItemNote"},directives:[]}]}}]}}]}}]}}]}}]}}]}}]}}]}}]}}],loc:{start:0,end:771}};t.loc.source={body:'#import "~/graphql_shared/fragments/page_info.fragment.graphql"\n#import "./work_item_note.fragment.graphql"\n\nquery workItemNotesByIid($fullPath: ID!, $iid: String, $after: String, $pageSize: Int) {\n  workspace: project(fullPath: $fullPath) {\n    id\n    workItems(iid: $iid) {\n      nodes {\n        id\n        iid\n        widgets {\n          ... on WorkItemWidgetNotes {\n            type\n            discussions(first: $pageSize, after: $after, filter: ALL_NOTES) {\n              pageInfo {\n                ...PageInfo\n              }\n              nodes {\n                id\n                notes {\n                  nodes {\n                    ...WorkItemNote\n                  }\n                }\n              }\n            }\n          }\n        }\n      }\n    }\n  }\n}\n',name:"GraphQL request",locationOffset:{line:1,column:1}};var a={};function d(e){return e.filter((function(e){if("FragmentDefinition"!==e.kind)return!0;var n=e.name.value;return!a[n]&&(a[n]=!0,!0)}))}t.definitions=t.definitions.concat(d(i("IVfO").definitions)),t.definitions=t.definitions.concat(d(i("3FDJ").definitions));var r={};function o(e,n){for(var i=0;i<e.definitions.length;i++){var t=e.definitions[i];if(t.name&&t.name.value==n)return t}}t.definitions.forEach((function(e){if(e.name){var n=new Set;!function e(n,i){if("FragmentSpread"===n.kind)i.add(n.name.value);else if("VariableDefinition"===n.kind){var t=n.type;"NamedType"===t.kind&&i.add(t.name.value)}n.selectionSet&&n.selectionSet.selections.forEach((function(n){e(n,i)})),n.variableDefinitions&&n.variableDefinitions.forEach((function(n){e(n,i)})),n.definitions&&n.definitions.forEach((function(n){e(n,i)}))}(e,n),r[e.name.value]=n}})),e.exports=t,e.exports.workItemNotesByIid=function(e,n){var i={kind:e.kind,definitions:[o(e,n)]};e.hasOwnProperty("loc")&&(i.loc=e.loc);var t=r[n]||new Set,a=new Set,d=new Set;for(t.forEach((function(e){d.add(e)}));d.size>0;){var s=d;d=new Set,s.forEach((function(e){a.has(e)||(a.add(e),(r[e]||new Set).forEach((function(e){d.add(e)})))}))}return a.forEach((function(n){var t=o(e,n);t&&i.definitions.push(t)})),i}(t,"workItemNotesByIid")},"3FDJ":function(e,n,i){var t={kind:"Document",definitions:[{kind:"FragmentDefinition",name:{kind:"Name",value:"WorkItemNote"},typeCondition:{kind:"NamedType",name:{kind:"Name",value:"Note"}},directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"Field",name:{kind:"Name",value:"id"},arguments:[],directives:[]},{kind:"Field",name:{kind:"Name",value:"body"},arguments:[],directives:[]},{kind:"Field",name:{kind:"Name",value:"bodyHtml"},arguments:[],directives:[]},{kind:"Field",name:{kind:"Name",value:"system"},arguments:[],directives:[]},{kind:"Field",name:{kind:"Name",value:"internal"},arguments:[],directives:[]},{kind:"Field",name:{kind:"Name",value:"systemNoteIconName"},arguments:[],directives:[]},{kind:"Field",name:{kind:"Name",value:"createdAt"},arguments:[],directives:[]},{kind:"Field",name:{kind:"Name",value:"lastEditedAt"},arguments:[],directives:[]},{kind:"Field",name:{kind:"Name",value:"lastEditedBy"},arguments:[],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"FragmentSpread",name:{kind:"Name",value:"User"},directives:[]},{kind:"Field",name:{kind:"Name",value:"webPath"},arguments:[],directives:[]}]}},{kind:"Field",name:{kind:"Name",value:"discussion"},arguments:[],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"Field",name:{kind:"Name",value:"id"},arguments:[],directives:[]}]}},{kind:"Field",name:{kind:"Name",value:"author"},arguments:[],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"FragmentSpread",name:{kind:"Name",value:"User"},directives:[]}]}},{kind:"Field",name:{kind:"Name",value:"userPermissions"},arguments:[],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"Field",name:{kind:"Name",value:"adminNote"},arguments:[],directives:[]},{kind:"Field",name:{kind:"Name",value:"awardEmoji"},arguments:[],directives:[]},{kind:"Field",name:{kind:"Name",value:"readNote"},arguments:[],directives:[]},{kind:"Field",name:{kind:"Name",value:"createNote"},arguments:[],directives:[]},{kind:"Field",name:{kind:"Name",value:"resolveNote"},arguments:[],directives:[]},{kind:"Field",name:{kind:"Name",value:"repositionNote"},arguments:[],directives:[]}]}}]}}],loc:{start:0,end:399}};t.loc.source={body:'#import "~/graphql_shared/fragments/user.fragment.graphql"\n\nfragment WorkItemNote on Note {\n  id\n  body\n  bodyHtml\n  system\n  internal\n  systemNoteIconName\n  createdAt\n  lastEditedAt\n  lastEditedBy {\n    ...User\n    webPath\n  }\n  discussion {\n    id\n  }\n  author {\n    ...User\n  }\n  userPermissions {\n    adminNote\n    awardEmoji\n    readNote\n    createNote\n    resolveNote\n    repositionNote\n  }\n}\n',name:"GraphQL request",locationOffset:{line:1,column:1}};var a={};t.definitions=t.definitions.concat(i("yXJ/").definitions.filter((function(e){if("FragmentDefinition"!==e.kind)return!0;var n=e.name.value;return!a[n]&&(a[n]=!0,!0)})));var d={};function r(e,n){for(var i=0;i<e.definitions.length;i++){var t=e.definitions[i];if(t.name&&t.name.value==n)return t}}t.definitions.forEach((function(e){if(e.name){var n=new Set;!function e(n,i){if("FragmentSpread"===n.kind)i.add(n.name.value);else if("VariableDefinition"===n.kind){var t=n.type;"NamedType"===t.kind&&i.add(t.name.value)}n.selectionSet&&n.selectionSet.selections.forEach((function(n){e(n,i)})),n.variableDefinitions&&n.variableDefinitions.forEach((function(n){e(n,i)})),n.definitions&&n.definitions.forEach((function(n){e(n,i)}))}(e,n),d[e.name.value]=n}})),e.exports=t,e.exports.WorkItemNote=function(e,n){var i={kind:e.kind,definitions:[r(e,n)]};e.hasOwnProperty("loc")&&(i.loc=e.loc);var t=d[n]||new Set,a=new Set,o=new Set;for(t.forEach((function(e){o.add(e)}));o.size>0;){var s=o;o=new Set,s.forEach((function(e){a.has(e)||(a.add(e),(d[e]||new Set).forEach((function(e){o.add(e)})))}))}return a.forEach((function(n){var t=r(e,n);t&&i.definitions.push(t)})),i}(t,"WorkItemNote")},Aiz4:function(e,n){var i={kind:"Document",definitions:[{kind:"OperationDefinition",operation:"query",name:{kind:"Name",value:"issueState"},variableDefinitions:[],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"Field",name:{kind:"Name",value:"issueState"},arguments:[],directives:[{kind:"Directive",name:{kind:"Name",value:"client"},arguments:[]}]}]}}],loc:{start:0,end:42}};i.loc.source={body:"query issueState {\n  issueState @client\n}\n",name:"GraphQL request",locationOffset:{line:1,column:1}};var t={};function a(e,n){for(var i=0;i<e.definitions.length;i++){var t=e.definitions[i];if(t.name&&t.name.value==n)return t}}i.definitions.forEach((function(e){if(e.name){var n=new Set;!function e(n,i){if("FragmentSpread"===n.kind)i.add(n.name.value);else if("VariableDefinition"===n.kind){var t=n.type;"NamedType"===t.kind&&i.add(t.name.value)}n.selectionSet&&n.selectionSet.selections.forEach((function(n){e(n,i)})),n.variableDefinitions&&n.variableDefinitions.forEach((function(n){e(n,i)})),n.definitions&&n.definitions.forEach((function(n){e(n,i)}))}(e,n),t[e.name.value]=n}})),e.exports=i,e.exports.issueState=function(e,n){var i={kind:e.kind,definitions:[a(e,n)]};e.hasOwnProperty("loc")&&(i.loc=e.loc);var d=t[n]||new Set,r=new Set,o=new Set;for(d.forEach((function(e){o.add(e)}));o.size>0;){var s=o;o=new Set,s.forEach((function(e){r.has(e)||(r.add(e),(t[e]||new Set).forEach((function(e){o.add(e)})))}))}return r.forEach((function(n){var t=a(e,n);t&&i.definitions.push(t)})),i}(i,"issueState")},DDJJ:function(e,n){var i={kind:"Document",definitions:[{kind:"EnumTypeDefinition",name:{kind:"Name",value:"LocalWidgetType"},directives:[],values:[{kind:"EnumValueDefinition",name:{kind:"Name",value:"ASSIGNEES"},directives:[]}]},{kind:"InterfaceTypeDefinition",name:{kind:"Name",value:"LocalWorkItemWidget"},interfaces:[],directives:[],fields:[{kind:"FieldDefinition",name:{kind:"Name",value:"type"},arguments:[],type:{kind:"NonNullType",type:{kind:"NamedType",name:{kind:"Name",value:"LocalWidgetType"}}},directives:[]}]},{kind:"ObjectTypeDefinition",name:{kind:"Name",value:"LocalWorkItemAssignees"},interfaces:[{kind:"NamedType",name:{kind:"Name",value:"LocalWorkItemWidget"}}],directives:[],fields:[{kind:"FieldDefinition",name:{kind:"Name",value:"type"},arguments:[],type:{kind:"NonNullType",type:{kind:"NamedType",name:{kind:"Name",value:"LocalWidgetType"}}},directives:[]},{kind:"FieldDefinition",name:{kind:"Name",value:"nodes"},arguments:[],type:{kind:"ListType",type:{kind:"NamedType",name:{kind:"Name",value:"UserCore"}}},directives:[]}]},{kind:"ObjectTypeExtension",name:{kind:"Name",value:"WorkItem"},interfaces:[],directives:[],fields:[{kind:"FieldDefinition",name:{kind:"Name",value:"mockWidgets"},arguments:[],type:{kind:"ListType",type:{kind:"NamedType",name:{kind:"Name",value:"LocalWorkItemWidget"}}},directives:[]}]},{kind:"InputObjectTypeDefinition",name:{kind:"Name",value:"LocalUserInput"},directives:[],fields:[{kind:"InputValueDefinition",name:{kind:"Name",value:"id"},type:{kind:"NonNullType",type:{kind:"NamedType",name:{kind:"Name",value:"ID"}}},directives:[]},{kind:"InputValueDefinition",name:{kind:"Name",value:"name"},type:{kind:"NamedType",name:{kind:"Name",value:"String"}},directives:[]},{kind:"InputValueDefinition",name:{kind:"Name",value:"username"},type:{kind:"NamedType",name:{kind:"Name",value:"String"}},directives:[]},{kind:"InputValueDefinition",name:{kind:"Name",value:"webUrl"},type:{kind:"NamedType",name:{kind:"Name",value:"String"}},directives:[]},{kind:"InputValueDefinition",name:{kind:"Name",value:"avatarUrl"},type:{kind:"NamedType",name:{kind:"Name",value:"String"}},directives:[]}]},{kind:"InputObjectTypeDefinition",name:{kind:"Name",value:"LocalUpdateWorkItemInput"},directives:[],fields:[{kind:"InputValueDefinition",name:{kind:"Name",value:"id"},type:{kind:"NonNullType",type:{kind:"NamedType",name:{kind:"Name",value:"WorkItemID"}}},directives:[]},{kind:"InputValueDefinition",name:{kind:"Name",value:"assignees"},type:{kind:"ListType",type:{kind:"NonNullType",type:{kind:"NamedType",name:{kind:"Name",value:"LocalUserInput"}}}},directives:[]}]},{kind:"ObjectTypeDefinition",name:{kind:"Name",value:"LocalWorkItemPayload"},interfaces:[],directives:[],fields:[{kind:"FieldDefinition",name:{kind:"Name",value:"workItem"},arguments:[],type:{kind:"NonNullType",type:{kind:"NamedType",name:{kind:"Name",value:"WorkItem"}}},directives:[]},{kind:"FieldDefinition",name:{kind:"Name",value:"errors"},arguments:[],type:{kind:"ListType",type:{kind:"NonNullType",type:{kind:"NamedType",name:{kind:"Name",value:"String"}}}},directives:[]}]},{kind:"ObjectTypeExtension",name:{kind:"Name",value:"Mutation"},interfaces:[],directives:[],fields:[{kind:"FieldDefinition",name:{kind:"Name",value:"localUpdateWorkItem"},arguments:[{kind:"InputValueDefinition",name:{kind:"Name",value:"input"},type:{kind:"NonNullType",type:{kind:"NamedType",name:{kind:"Name",value:"LocalUpdateWorkItemInput"}}},directives:[]}],type:{kind:"NamedType",name:{kind:"Name",value:"LocalWorkItemPayload"}},directives:[]}]}],loc:{start:0,end:638}};i.loc.source={body:"enum LocalWidgetType {\n  ASSIGNEES\n}\n\ninterface LocalWorkItemWidget {\n  type: LocalWidgetType!\n}\n\ntype LocalWorkItemAssignees implements LocalWorkItemWidget {\n  type: LocalWidgetType!\n  nodes: [UserCore]\n}\n\nextend type WorkItem {\n  mockWidgets: [LocalWorkItemWidget]\n}\n\ninput LocalUserInput {\n  id: ID!\n  name: String\n  username: String\n  webUrl: String\n  avatarUrl: String\n}\n\ninput LocalUpdateWorkItemInput {\n  id: WorkItemID!\n  assignees: [LocalUserInput!]\n}\n\ntype LocalWorkItemPayload {\n  workItem: WorkItem!\n  errors: [String!]\n}\n\nextend type Mutation {\n  localUpdateWorkItem(input: LocalUpdateWorkItemInput!): LocalWorkItemPayload\n}\n",name:"GraphQL request",locationOffset:{line:1,column:1}};e.exports=i},DNao:function(e,n,i){var t={kind:"Document",definitions:[{kind:"OperationDefinition",operation:"query",name:{kind:"Name",value:"workItem"},variableDefinitions:[{kind:"VariableDefinition",variable:{kind:"Variable",name:{kind:"Name",value:"id"}},type:{kind:"NonNullType",type:{kind:"NamedType",name:{kind:"Name",value:"WorkItemID"}}},directives:[]}],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"Field",name:{kind:"Name",value:"workItem"},arguments:[{kind:"Argument",name:{kind:"Name",value:"id"},value:{kind:"Variable",name:{kind:"Name",value:"id"}}}],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"FragmentSpread",name:{kind:"Name",value:"WorkItem"},directives:[]}]}}]}}],loc:{start:0,end:119}};t.loc.source={body:'#import "./work_item.fragment.graphql"\n\nquery workItem($id: WorkItemID!) {\n  workItem(id: $id) {\n    ...WorkItem\n  }\n}\n',name:"GraphQL request",locationOffset:{line:1,column:1}};var a={};t.definitions=t.definitions.concat(i("nLMr").definitions.filter((function(e){if("FragmentDefinition"!==e.kind)return!0;var n=e.name.value;return!a[n]&&(a[n]=!0,!0)})));var d={};function r(e,n){for(var i=0;i<e.definitions.length;i++){var t=e.definitions[i];if(t.name&&t.name.value==n)return t}}t.definitions.forEach((function(e){if(e.name){var n=new Set;!function e(n,i){if("FragmentSpread"===n.kind)i.add(n.name.value);else if("VariableDefinition"===n.kind){var t=n.type;"NamedType"===t.kind&&i.add(t.name.value)}n.selectionSet&&n.selectionSet.selections.forEach((function(n){e(n,i)})),n.variableDefinitions&&n.variableDefinitions.forEach((function(n){e(n,i)})),n.definitions&&n.definitions.forEach((function(n){e(n,i)}))}(e,n),d[e.name.value]=n}})),e.exports=t,e.exports.workItem=function(e,n){var i={kind:e.kind,definitions:[r(e,n)]};e.hasOwnProperty("loc")&&(i.loc=e.loc);var t=d[n]||new Set,a=new Set,o=new Set;for(t.forEach((function(e){o.add(e)}));o.size>0;){var s=o;o=new Set,s.forEach((function(e){a.has(e)||(a.add(e),(d[e]||new Set).forEach((function(e){o.add(e)})))}))}return a.forEach((function(n){var t=r(e,n);t&&i.definitions.push(t)})),i}(t,"workItem")},Musk:function(e,n,i){var t={kind:"Document",definitions:[{kind:"OperationDefinition",operation:"query",name:{kind:"Name",value:"workItemByIid"},variableDefinitions:[{kind:"VariableDefinition",variable:{kind:"Variable",name:{kind:"Name",value:"fullPath"}},type:{kind:"NonNullType",type:{kind:"NamedType",name:{kind:"Name",value:"ID"}}},directives:[]},{kind:"VariableDefinition",variable:{kind:"Variable",name:{kind:"Name",value:"iid"}},type:{kind:"NamedType",name:{kind:"Name",value:"String"}},directives:[]}],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"Field",alias:{kind:"Name",value:"workspace"},name:{kind:"Name",value:"project"},arguments:[{kind:"Argument",name:{kind:"Name",value:"fullPath"},value:{kind:"Variable",name:{kind:"Name",value:"fullPath"}}}],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"Field",name:{kind:"Name",value:"id"},arguments:[],directives:[]},{kind:"Field",name:{kind:"Name",value:"workItems"},arguments:[{kind:"Argument",name:{kind:"Name",value:"iid"},value:{kind:"Variable",name:{kind:"Name",value:"iid"}}}],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"Field",name:{kind:"Name",value:"nodes"},arguments:[],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"FragmentSpread",name:{kind:"Name",value:"WorkItem"},directives:[]}]}}]}}]}}]}}],loc:{start:0,end:224}};t.loc.source={body:'#import "./work_item.fragment.graphql"\n\nquery workItemByIid($fullPath: ID!, $iid: String) {\n  workspace: project(fullPath: $fullPath) {\n    id\n    workItems(iid: $iid) {\n      nodes {\n        ...WorkItem\n      }\n    }\n  }\n}\n',name:"GraphQL request",locationOffset:{line:1,column:1}};var a={};t.definitions=t.definitions.concat(i("nLMr").definitions.filter((function(e){if("FragmentDefinition"!==e.kind)return!0;var n=e.name.value;return!a[n]&&(a[n]=!0,!0)})));var d={};function r(e,n){for(var i=0;i<e.definitions.length;i++){var t=e.definitions[i];if(t.name&&t.name.value==n)return t}}t.definitions.forEach((function(e){if(e.name){var n=new Set;!function e(n,i){if("FragmentSpread"===n.kind)i.add(n.name.value);else if("VariableDefinition"===n.kind){var t=n.type;"NamedType"===t.kind&&i.add(t.name.value)}n.selectionSet&&n.selectionSet.selections.forEach((function(n){e(n,i)})),n.variableDefinitions&&n.variableDefinitions.forEach((function(n){e(n,i)})),n.definitions&&n.definitions.forEach((function(n){e(n,i)}))}(e,n),d[e.name.value]=n}})),e.exports=t,e.exports.workItemByIid=function(e,n){var i={kind:e.kind,definitions:[r(e,n)]};e.hasOwnProperty("loc")&&(i.loc=e.loc);var t=d[n]||new Set,a=new Set,o=new Set;for(t.forEach((function(e){o.add(e)}));o.size>0;){var s=o;o=new Set,s.forEach((function(e){a.has(e)||(a.add(e),(d[e]||new Set).forEach((function(e){o.add(e)})))}))}return a.forEach((function(n){var t=r(e,n);t&&i.definitions.push(t)})),i}(t,"workItemByIid")},"Ose/":function(e,n){var i={kind:"Document",definitions:[{kind:"OperationDefinition",operation:"query",name:{kind:"Name",value:"workItemLinksQuery"},variableDefinitions:[{kind:"VariableDefinition",variable:{kind:"Variable",name:{kind:"Name",value:"id"}},type:{kind:"NonNullType",type:{kind:"NamedType",name:{kind:"Name",value:"WorkItemID"}}},directives:[]}],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"Field",name:{kind:"Name",value:"workItem"},arguments:[{kind:"Argument",name:{kind:"Name",value:"id"},value:{kind:"Variable",name:{kind:"Name",value:"id"}}}],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"Field",name:{kind:"Name",value:"id"},arguments:[],directives:[]},{kind:"Field",name:{kind:"Name",value:"workItemType"},arguments:[],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"Field",name:{kind:"Name",value:"id"},arguments:[],directives:[]},{kind:"Field",name:{kind:"Name",value:"name"},arguments:[],directives:[]}]}},{kind:"Field",name:{kind:"Name",value:"title"},arguments:[],directives:[]},{kind:"Field",name:{kind:"Name",value:"userPermissions"},arguments:[],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"Field",name:{kind:"Name",value:"deleteWorkItem"},arguments:[],directives:[]},{kind:"Field",name:{kind:"Name",value:"updateWorkItem"},arguments:[],directives:[]}]}},{kind:"Field",name:{kind:"Name",value:"confidential"},arguments:[],directives:[]},{kind:"Field",name:{kind:"Name",value:"widgets"},arguments:[],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"Field",name:{kind:"Name",value:"type"},arguments:[],directives:[]},{kind:"InlineFragment",typeCondition:{kind:"NamedType",name:{kind:"Name",value:"WorkItemWidgetHierarchy"}},directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"Field",name:{kind:"Name",value:"type"},arguments:[],directives:[]},{kind:"Field",name:{kind:"Name",value:"parent"},arguments:[],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"Field",name:{kind:"Name",value:"id"},arguments:[],directives:[]}]}},{kind:"Field",name:{kind:"Name",value:"children"},arguments:[],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"Field",name:{kind:"Name",value:"nodes"},arguments:[],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"Field",name:{kind:"Name",value:"id"},arguments:[],directives:[]},{kind:"Field",name:{kind:"Name",value:"iid"},arguments:[],directives:[]},{kind:"Field",name:{kind:"Name",value:"confidential"},arguments:[],directives:[]},{kind:"Field",name:{kind:"Name",value:"workItemType"},arguments:[],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"Field",name:{kind:"Name",value:"id"},arguments:[],directives:[]},{kind:"Field",name:{kind:"Name",value:"name"},arguments:[],directives:[]},{kind:"Field",name:{kind:"Name",value:"iconName"},arguments:[],directives:[]}]}},{kind:"Field",name:{kind:"Name",value:"title"},arguments:[],directives:[]},{kind:"Field",name:{kind:"Name",value:"state"},arguments:[],directives:[]},{kind:"Field",name:{kind:"Name",value:"createdAt"},arguments:[],directives:[]},{kind:"Field",name:{kind:"Name",value:"closedAt"},arguments:[],directives:[]}]}}]}}]}}]}}]}}]}}],loc:{start:0,end:647}};i.loc.source={body:"query workItemLinksQuery($id: WorkItemID!) {\n  workItem(id: $id) {\n    id\n    workItemType {\n      id\n      name\n    }\n    title\n    userPermissions {\n      deleteWorkItem\n      updateWorkItem\n    }\n    confidential\n    widgets {\n      type\n      ... on WorkItemWidgetHierarchy {\n        type\n        parent {\n          id\n        }\n        children {\n          nodes {\n            id\n            iid\n            confidential\n            workItemType {\n              id\n              name\n              iconName\n            }\n            title\n            state\n            createdAt\n            closedAt\n          }\n        }\n      }\n    }\n  }\n}\n",name:"GraphQL request",locationOffset:{line:1,column:1}};var t={};function a(e,n){for(var i=0;i<e.definitions.length;i++){var t=e.definitions[i];if(t.name&&t.name.value==n)return t}}i.definitions.forEach((function(e){if(e.name){var n=new Set;!function e(n,i){if("FragmentSpread"===n.kind)i.add(n.name.value);else if("VariableDefinition"===n.kind){var t=n.type;"NamedType"===t.kind&&i.add(t.name.value)}n.selectionSet&&n.selectionSet.selections.forEach((function(n){e(n,i)})),n.variableDefinitions&&n.variableDefinitions.forEach((function(n){e(n,i)})),n.definitions&&n.definitions.forEach((function(n){e(n,i)}))}(e,n),t[e.name.value]=n}})),e.exports=i,e.exports.workItemLinksQuery=function(e,n){var i={kind:e.kind,definitions:[a(e,n)]};e.hasOwnProperty("loc")&&(i.loc=e.loc);var d=t[n]||new Set,r=new Set,o=new Set;for(d.forEach((function(e){o.add(e)}));o.size>0;){var s=o;o=new Set,s.forEach((function(e){r.has(e)||(r.add(e),(t[e]||new Set).forEach((function(e){o.add(e)})))}))}return r.forEach((function(n){var t=a(e,n);t&&i.definitions.push(t)})),i}(i,"workItemLinksQuery")},ZfsP:function(e,n,i){"use strict";i.d(n,"b",(function(){return y})),i.d(n,"a",(function(){return I}));i("uHfJ"),i("R0RX"),i("WmlO"),i("3R5X"),i("W9Nl");var t,a,d=i("ENs1"),r=i("EfTh"),o=i("P9JE"),s=i("1/rY"),l=i("Aiz4"),m=i.n(l),u=i("voi4"),c=i("DDJJ"),k=i.n(c),v=i("XXQe"),f=i("Ose/"),p=i.n(f),N=i("jiUj");const g={typeDefs:k(),cacheConfig:{dataIdFromObject:function(e){var n,i;return"BoardList"!==e.__typename||null!==(n=window.gon)&&void 0!==n&&null!==(i=n.features)&&void 0!==i&&i.apolloBoards?Object(o.b)(e):e.iid},typePolicies:{Project:{fields:{projectMembers:{keyArgs:["fullPath","search","relations","first"]}}},WorkItemWidgetNotes:{fields:{discussions:{keyArgs:!1}}},WorkItemWidgetProgress:{fields:{progress:{read:e=>null===e?0:e}}},WorkItem:{fields:{widgets:{merge(){let e=arguments.length>0&&void 0!==arguments[0]?arguments[0]:[],n=arguments.length>1?arguments[1]:void 0,i=arguments.length>2?arguments[2]:void 0;return 0===e.length?n:e.map((function(e){const t=n.find((function(n){return n.type&&n.type===e.type}));return(null==t?void 0:t.type)!==v.F||i.variables.pageSize?(null==t?void 0:t.type)===v.F&&i.variables.after?{...t,discussions:{...t.discussions,nodes:[...e.discussions.nodes,...t.discussions.nodes]}}:t||e:e}))}}}},MemberInterfaceConnection:{fields:{nodes:Object(s.a)()}},...null!==(t=window.gon)&&void 0!==t&&null!==(a=t.features)&&void 0!==a&&a.apolloBoards?{BoardList:{fields:{issues:{keyArgs:["filters"]}}},IssueConnection:{merge(){let e=arguments.length>0&&void 0!==arguments[0]?arguments[0]:{nodes:[]},n=arguments.length>1?arguments[1]:void 0,{args:i}=arguments.length>2?arguments[2]:void 0;return i.after?{...n,nodes:[...e.nodes,...n.nodes]}:n}},EpicList:{fields:{epics:{keyArgs:["filters"]}}},EpicConnection:{merge(){let e=arguments.length>0&&void 0!==arguments[0]?arguments[0]:{nodes:[]},n=arguments.length>1?arguments[1]:void 0,{args:i}=arguments.length>2?arguments[2]:void 0;return i.after?{...n,nodes:[...e.nodes,...n.nodes]}:n}},BoardEpicConnection:{merge(){let e=arguments.length>0&&void 0!==arguments[0]?arguments[0]:{nodes:[]},n=arguments.length>1?arguments[1]:void 0,{args:i}=arguments.length>2?arguments[2]:void 0;return i.after?{...n,nodes:[...e.nodes,...n.nodes]}:n}}}:{}}}},S={Mutation:{addHierarchyChild:function(e,n,i){let{id:t,workItem:a}=n,{cache:r}=i;const o={query:p.a,variables:{id:t}},s=r.readQuery(o),l=Object(d.a)(s,(function(e){Object(N.b)(e.workItem).push(a)}));r.writeQuery({...o,data:l})},removeHierarchyChild:function(e,n,i){let{id:t,workItem:a}=n,{cache:r}=i;const o={query:p.a,variables:{id:t}},s=r.readQuery(o),l=Object(d.a)(s,(function(e){const n=Object(N.b)(e.workItem),i=n.findIndex((function(e){return e.id===a.id}));n.splice(i,1)}));r.writeQuery({...o,data:l})},updateIssueState:function(e,n,i){let{issueType:t,isDirty:a=!1}=n,{cache:r}=i;const o=r.readQuery({query:m.a}),s=Object(d.a)(o,(function(e){e.issueState={issueType:t,isDirty:a}}));r.writeQuery({query:m.a,data:s})}}},y=Object(u.a)(S,g),I=new r.b({defaultClient:y})},jiUj:function(e,n,i){"use strict";i.d(n,"d",(function(){return c})),i.d(n,"c",(function(){return k})),i.d(n,"b",(function(){return v})),i.d(n,"a",(function(){return p})),i.d(n,"e",(function(){return N}));i("WmlO"),i("3R5X"),i("W9Nl");var t=i("XXQe"),a=i("DNao"),d=i.n(a),r=i("Musk"),o=i.n(r),s=i("k5+B"),l=i.n(s),m=i("2UZr"),u=i.n(m);function c(e){return e?o.a:d.a}function k(e){return e?u.a:l.a}const v=function(e){return e.widgets.find((function(e){return e.type===t.B})).children.nodes},f=function(e,n,i){return`${gon.relative_url_root||""}/${n}/-/autocomplete_sources/${e}?type=WorkItem&type_id=${i}`},p=function(e,n){return{labels:f("labels",e,n),members:f("members",e,n),commands:f("commands",e,n)}},N=function(e,n){return`${gon.relative_url_root||""}/${e}/preview_markdown?target_type=WorkItem&target_id=${n}`}},"k5+B":function(e,n,i){var t={kind:"Document",definitions:[{kind:"OperationDefinition",operation:"query",name:{kind:"Name",value:"workItemNotes"},variableDefinitions:[{kind:"VariableDefinition",variable:{kind:"Variable",name:{kind:"Name",value:"id"}},type:{kind:"NonNullType",type:{kind:"NamedType",name:{kind:"Name",value:"WorkItemID"}}},directives:[]},{kind:"VariableDefinition",variable:{kind:"Variable",name:{kind:"Name",value:"after"}},type:{kind:"NamedType",name:{kind:"Name",value:"String"}},directives:[]},{kind:"VariableDefinition",variable:{kind:"Variable",name:{kind:"Name",value:"pageSize"}},type:{kind:"NamedType",name:{kind:"Name",value:"Int"}},directives:[]}],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"Field",name:{kind:"Name",value:"workItem"},arguments:[{kind:"Argument",name:{kind:"Name",value:"id"},value:{kind:"Variable",name:{kind:"Name",value:"id"}}}],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"Field",name:{kind:"Name",value:"id"},arguments:[],directives:[]},{kind:"Field",name:{kind:"Name",value:"iid"},arguments:[],directives:[]},{kind:"Field",name:{kind:"Name",value:"widgets"},arguments:[],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"InlineFragment",typeCondition:{kind:"NamedType",name:{kind:"Name",value:"WorkItemWidgetNotes"}},directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"Field",name:{kind:"Name",value:"type"},arguments:[],directives:[]},{kind:"Field",name:{kind:"Name",value:"discussions"},arguments:[{kind:"Argument",name:{kind:"Name",value:"first"},value:{kind:"Variable",name:{kind:"Name",value:"pageSize"}}},{kind:"Argument",name:{kind:"Name",value:"after"},value:{kind:"Variable",name:{kind:"Name",value:"after"}}},{kind:"Argument",name:{kind:"Name",value:"filter"},value:{kind:"EnumValue",value:"ALL_NOTES"}}],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"Field",name:{kind:"Name",value:"pageInfo"},arguments:[],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"FragmentSpread",name:{kind:"Name",value:"PageInfo"},directives:[]}]}},{kind:"Field",name:{kind:"Name",value:"nodes"},arguments:[],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"Field",name:{kind:"Name",value:"id"},arguments:[],directives:[]},{kind:"Field",name:{kind:"Name",value:"notes"},arguments:[],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"Field",name:{kind:"Name",value:"nodes"},arguments:[],directives:[],selectionSet:{kind:"SelectionSet",selections:[{kind:"FragmentSpread",name:{kind:"Name",value:"WorkItemNote"},directives:[]}]}}]}}]}}]}}]}}]}}]}}]}}],loc:{start:0,end:590}};t.loc.source={body:'#import "~/graphql_shared/fragments/page_info.fragment.graphql"\n#import "./work_item_note.fragment.graphql"\n\nquery workItemNotes($id: WorkItemID!, $after: String, $pageSize: Int) {\n  workItem(id: $id) {\n    id\n    iid\n    widgets {\n      ... on WorkItemWidgetNotes {\n        type\n        discussions(first: $pageSize, after: $after, filter: ALL_NOTES) {\n          pageInfo {\n            ...PageInfo\n          }\n          nodes {\n            id\n            notes {\n              nodes {\n                ...WorkItemNote\n              }\n            }\n          }\n        }\n      }\n    }\n  }\n}\n',name:"GraphQL request",locationOffset:{line:1,column:1}};var a={};function d(e){return e.filter((function(e){if("FragmentDefinition"!==e.kind)return!0;var n=e.name.value;return!a[n]&&(a[n]=!0,!0)}))}t.definitions=t.definitions.concat(d(i("IVfO").definitions)),t.definitions=t.definitions.concat(d(i("3FDJ").definitions));var r={};function o(e,n){for(var i=0;i<e.definitions.length;i++){var t=e.definitions[i];if(t.name&&t.name.value==n)return t}}t.definitions.forEach((function(e){if(e.name){var n=new Set;!function e(n,i){if("FragmentSpread"===n.kind)i.add(n.name.value);else if("VariableDefinition"===n.kind){var t=n.type;"NamedType"===t.kind&&i.add(t.name.value)}n.selectionSet&&n.selectionSet.selections.forEach((function(n){e(n,i)})),n.variableDefinitions&&n.variableDefinitions.forEach((function(n){e(n,i)})),n.definitions&&n.definitions.forEach((function(n){e(n,i)}))}(e,n),r[e.name.value]=n}})),e.exports=t,e.exports.workItemNotes=function(e,n){var i={kind:e.kind,definitions:[o(e,n)]};e.hasOwnProperty("loc")&&(i.loc=e.loc);var t=r[n]||new Set,a=new Set,d=new Set;for(t.forEach((function(e){d.add(e)}));d.size>0;){var s=d;d=new Set,s.forEach((function(e){a.has(e)||(a.add(e),(r[e]||new Set).forEach((function(e){d.add(e)})))}))}return a.forEach((function(n){var t=o(e,n);t&&i.definitions.push(t)})),i}(t,"workItemNotes")}}]);
//# sourceMappingURL=commons-pages.groups.boards-pages.groups.epic_boards-pages.groups.epics.show-pages.groups.merge_requ-8444deba.5431d304.chunk.js.map