/* Automatically generated.  Do not edit */
/* See the tool/mkopcodeh.tcl script for details */
#define OP_Savepoint       0
#define OP_AutoCommit      1
#define OP_Transaction     2
#define OP_SorterNext      3 /* jump                                       */
#define OP_Prev            4 /* jump                                       */
#define OP_Next            5 /* jump                                       */
#define OP_Checkpoint      6
#define OP_JournalMode     7
#define OP_Vacuum          8
#define OP_VFilter         9 /* jump, synopsis: iplan=r[P3] zplan='P4'     */
#define OP_VUpdate        10 /* synopsis: data=r[P3@P2]                    */
#define OP_Goto           11 /* jump                                       */
#define OP_Gosub          12 /* jump                                       */
#define OP_InitCoroutine  13 /* jump                                       */
#define OP_Yield          14 /* jump                                       */
#define OP_MustBeInt      15 /* jump                                       */
#define OP_Jump           16 /* jump                                       */
#define OP_Once           17 /* jump                                       */
#define OP_If             18 /* jump                                       */
#define OP_Not            19 /* same as TK_NOT, synopsis: r[P2]= !r[P1]    */
#define OP_IfNot          20 /* jump                                       */
#define OP_IsNullOrType   21 /* jump, synopsis: if typeof(r[P1]) IN (P3,5) goto P2 */
#define OP_IfNullRow      22 /* jump, synopsis: if P1.nullRow then r[P3]=NULL, goto P2 */
#define OP_SeekLT         23 /* jump, synopsis: key=r[P3@P4]               */
#define OP_SeekLE         24 /* jump, synopsis: key=r[P3@P4]               */
#define OP_SeekGE         25 /* jump, synopsis: key=r[P3@P4]               */
#define OP_SeekGT         26 /* jump, synopsis: key=r[P3@P4]               */
#define OP_IfNotOpen      27 /* jump, synopsis: if( !csr[P1] ) goto P2     */
#define OP_IfNoHope       28 /* jump, synopsis: key=r[P3@P4]               */
#define OP_NoConflict     29 /* jump, synopsis: key=r[P3@P4]               */
#define OP_NotFound       30 /* jump, synopsis: key=r[P3@P4]               */
#define OP_Found          31 /* jump, synopsis: key=r[P3@P4]               */
#define OP_SeekRowid      32 /* jump, synopsis: intkey=r[P3]               */
#define OP_NotExists      33 /* jump, synopsis: intkey=r[P3]               */
#define OP_Last           34 /* jump                                       */
#define OP_IfSmaller      35 /* jump                                       */
#define OP_SorterSort     36 /* jump                                       */
#define OP_Sort           37 /* jump                                       */
#define OP_Rewind         38 /* jump                                       */
#define OP_IdxLE          39 /* jump, synopsis: key=r[P3@P4]               */
#define OP_IdxGT          40 /* jump, synopsis: key=r[P3@P4]               */
#define OP_IdxLT          41 /* jump, synopsis: key=r[P3@P4]               */
#define OP_IdxGE          42 /* jump, synopsis: key=r[P3@P4]               */
#define OP_Or             43 /* same as TK_OR, synopsis: r[P3]=(r[P1] || r[P2]) */
#define OP_And            44 /* same as TK_AND, synopsis: r[P3]=(r[P1] && r[P2]) */
#define OP_RowSetRead     45 /* jump, synopsis: r[P3]=rowset(P1)           */
#define OP_RowSetTest     46 /* jump, synopsis: if r[P3] in rowset(P1) goto P2 */
#define OP_Program        47 /* jump                                       */
#define OP_FkIfZero       48 /* jump, synopsis: if fkctr[P1]==0 goto P2    */
#define OP_IfPos          49 /* jump, synopsis: if r[P1]>0 then r[P1]-=P3, goto P2 */
#define OP_IsNull         50 /* jump, same as TK_ISNULL, synopsis: if r[P1]==NULL goto P2 */
#define OP_NotNull        51 /* jump, same as TK_NOTNULL, synopsis: if r[P1]!=NULL goto P2 */
#define OP_Ne             52 /* jump, same as TK_NE, synopsis: IF r[P3]!=r[P1] */
#define OP_Eq             53 /* jump, same as TK_EQ, synopsis: IF r[P3]==r[P1] */
#define OP_Gt             54 /* jump, same as TK_GT, synopsis: IF r[P3]>r[P1] */
#define OP_Le             55 /* jump, same as TK_LE, synopsis: IF r[P3]<=r[P1] */
#define OP_Lt             56 /* jump, same as TK_LT, synopsis: IF r[P3]<r[P1] */
#define OP_Ge             57 /* jump, same as TK_GE, synopsis: IF r[P3]>=r[P1] */
#define OP_ElseEq         58 /* jump, same as TK_ESCAPE                    */
#define OP_IfNotZero      59 /* jump, synopsis: if r[P1]!=0 then r[P1]--, goto P2 */
#define OP_DecrJumpZero   60 /* jump, synopsis: if (--r[P1])==0 goto P2    */
#define OP_IncrVacuum     61 /* jump                                       */
#define OP_VNext          62 /* jump                                       */
#define OP_Filter         63 /* jump, synopsis: if key(P3@P4) not in filter(P1) goto P2 */
#define OP_Init           64 /* jump, synopsis: Start at P2                */
#define OP_PureFunc       65 /* synopsis: r[P3]=func(r[P2@NP])             */
#define OP_Function       66 /* synopsis: r[P3]=func(r[P2@NP])             */
#define OP_Return         67
#define OP_EndCoroutine   68
#define OP_HaltIfNull     69 /* synopsis: if r[P3]=null halt               */
#define OP_Halt           70
#define OP_Integer        71 /* synopsis: r[P2]=P1                         */
#define OP_Int64          72 /* synopsis: r[P2]=P4                         */
#define OP_String         73 /* synopsis: r[P2]='P4' (len=P1)              */
#define OP_Null           74 /* synopsis: r[P2..P3]=NULL                   */
#define OP_SoftNull       75 /* synopsis: r[P1]=NULL                       */
#define OP_Blob           76 /* synopsis: r[P2]=P4 (len=P1)                */
#define OP_Variable       77 /* synopsis: r[P2]=parameter(P1,P4)           */
#define OP_Move           78 /* synopsis: r[P2@P3]=r[P1@P3]                */
#define OP_Copy           79 /* synopsis: r[P2@P3+1]=r[P1@P3+1]            */
#define OP_SCopy          80 /* synopsis: r[P2]=r[P1]                      */
#define OP_IntCopy        81 /* synopsis: r[P2]=r[P1]                      */
#define OP_FkCheck        82
#define OP_ResultRow      83 /* synopsis: output=r[P1@P2]                  */
#define OP_CollSeq        84
#define OP_AddImm         85 /* synopsis: r[P1]=r[P1]+P2                   */
#define OP_RealAffinity   86
#define OP_Cast           87 /* synopsis: affinity(r[P1])                  */
#define OP_Permutation    88
#define OP_Compare        89 /* synopsis: r[P1@P3] <-> r[P2@P3]            */
#define OP_IsTrue         90 /* synopsis: r[P2] = coalesce(r[P1]==TRUE,P3) ^ P4 */
#define OP_ZeroOrNull     91 /* synopsis: r[P2] = 0 OR NULL                */
#define OP_Offset         92 /* synopsis: r[P3] = sqlite_offset(P1)        */
#define OP_Column         93 /* synopsis: r[P3]=PX                         */
#define OP_TypeCheck      94 /* synopsis: typecheck(r[P1@P2])              */
#define OP_Affinity       95 /* synopsis: affinity(r[P1@P2])               */
#define OP_MakeRecord     96 /* synopsis: r[P3]=mkrec(r[P1@P2])            */
#define OP_Count          97 /* synopsis: r[P2]=count()                    */
#define OP_ReadCookie     98
#define OP_SetCookie      99
#define OP_ReopenIdx     100 /* synopsis: root=P2 iDb=P3                   */
#define OP_OpenRead      101 /* synopsis: root=P2 iDb=P3                   */
#define OP_BitAnd        102 /* same as TK_BITAND, synopsis: r[P3]=r[P1]&r[P2] */
#define OP_BitOr         103 /* same as TK_BITOR, synopsis: r[P3]=r[P1]|r[P2] */
#define OP_ShiftLeft     104 /* same as TK_LSHIFT, synopsis: r[P3]=r[P2]<<r[P1] */
#define OP_ShiftRight    105 /* same as TK_RSHIFT, synopsis: r[P3]=r[P2]>>r[P1] */
#define OP_Add           106 /* same as TK_PLUS, synopsis: r[P3]=r[P1]+r[P2] */
#define OP_Subtract      107 /* same as TK_MINUS, synopsis: r[P3]=r[P2]-r[P1] */
#define OP_Multiply      108 /* same as TK_STAR, synopsis: r[P3]=r[P1]*r[P2] */
#define OP_Divide        109 /* same as TK_SLASH, synopsis: r[P3]=r[P2]/r[P1] */
#define OP_Remainder     110 /* same as TK_REM, synopsis: r[P3]=r[P2]%r[P1] */
#define OP_Concat        111 /* same as TK_CONCAT, synopsis: r[P3]=r[P2]+r[P1] */
#define OP_OpenWrite     112 /* synopsis: root=P2 iDb=P3                   */
#define OP_OpenDup       113
#define OP_BitNot        114 /* same as TK_BITNOT, synopsis: r[P2]= ~r[P1] */
#define OP_OpenAutoindex 115 /* synopsis: nColumn=P2                       */
#define OP_OpenEphemeral 116 /* synopsis: nColumn=P2                       */
#define OP_String8       117 /* same as TK_STRING, synopsis: r[P2]='P4'    */
#define OP_SorterOpen    118
#define OP_SequenceTest  119 /* synopsis: if( cursor[P1].ctr++ ) pc = P2   */
#define OP_OpenPseudo    120 /* synopsis: P3 columns in r[P2]              */
#define OP_Close         121
#define OP_ColumnsUsed   122
#define OP_SeekScan      123 /* synopsis: Scan-ahead up to P1 rows         */
#define OP_SeekHit       124 /* synopsis: set P2<=seekHit<=P3              */
#define OP_Sequence      125 /* synopsis: r[P2]=cursor[P1].ctr++           */
#define OP_NewRowid      126 /* synopsis: r[P2]=rowid                      */
#define OP_Insert        127 /* synopsis: intkey=r[P3] data=r[P2]          */
#define OP_RowCell       128
#define OP_Delete        129
#define OP_ResetCount    130
#define OP_SorterCompare 131 /* synopsis: if key(P1)!=trim(r[P3],P4) goto P2 */
#define OP_SorterData    132 /* synopsis: r[P2]=data                       */
#define OP_RowData       133 /* synopsis: r[P2]=data                       */
#define OP_Rowid         134 /* synopsis: r[P2]=rowid                      */
#define OP_NullRow       135
#define OP_SeekEnd       136
#define OP_IdxInsert     137 /* synopsis: key=r[P2]                        */
#define OP_SorterInsert  138 /* synopsis: key=r[P2]                        */
#define OP_IdxDelete     139 /* synopsis: key=r[P2@P3]                     */
#define OP_DeferredSeek  140 /* synopsis: Move P3 to P1.rowid if needed    */
#define OP_IdxRowid      141 /* synopsis: r[P2]=rowid                      */
#define OP_FinishSeek    142
#define OP_Destroy       143
#define OP_Clear         144
#define OP_ResetSorter   145
#define OP_CreateBtree   146 /* synopsis: r[P2]=root iDb=P1 flags=P3       */
#define OP_SqlExec       147
#define OP_ParseSchema   148
#define OP_LoadAnalysis  149
#define OP_DropTable     150
#define OP_DropIndex     151
#define OP_DropTrigger   152
#define OP_Real          153 /* same as TK_FLOAT, synopsis: r[P2]=P4       */
#define OP_IntegrityCk   154
#define OP_RowSetAdd     155 /* synopsis: rowset(P1)=r[P2]                 */
#define OP_Param         156
#define OP_FkCounter     157 /* synopsis: fkctr[P1]+=P2                    */
#define OP_MemMax        158 /* synopsis: r[P1]=max(r[P1],r[P2])           */
#define OP_OffsetLimit   159 /* synopsis: if r[P1]>0 then r[P2]=r[P1]+max(0,r[P3]) else r[P2]=(-1) */
#define OP_AggInverse    160 /* synopsis: accum=r[P3] inverse(r[P2@P5])    */
#define OP_AggStep       161 /* synopsis: accum=r[P3] step(r[P2@P5])       */
#define OP_AggStep1      162 /* synopsis: accum=r[P3] step(r[P2@P5])       */
#define OP_AggValue      163 /* synopsis: r[P3]=value N=P2                 */
#define OP_AggFinal      164 /* synopsis: accum=r[P1] N=P2                 */
#define OP_Expire        165
#define OP_CursorLock    166
#define OP_CursorUnlock  167
#define OP_TableLock     168 /* synopsis: iDb=P1 root=P2 write=P3          */
#define OP_VBegin        169
#define OP_VCreate       170
#define OP_VDestroy      171
#define OP_VOpen         172
#define OP_VInitIn       173 /* synopsis: r[P2]=ValueList(P1,P3)           */
#define OP_VColumn       174 /* synopsis: r[P3]=vcolumn(P2)                */
#define OP_VRename       175
#define OP_Pagecount     176
#define OP_MaxPgcnt      177
#define OP_FilterAdd     178 /* synopsis: filter(P1) += key(P3@P4)         */
#define OP_Trace         179
#define OP_CursorHint    180
#define OP_ReleaseReg    181 /* synopsis: release r[P1@P2] mask P3         */
#define OP_Noop          182
#define OP_Explain       183
#define OP_Abortable     184

/* Properties such as "out2" or "jump" that are specified in
** comments following the "case" for each opcode in the vdbe.c
** are encoded into bitvectors as follows:
*/
#define OPFLG_JUMP        0x01  /* jump:  P2 holds jmp target */
#define OPFLG_IN1         0x02  /* in1:   P1 is an input */
#define OPFLG_IN2         0x04  /* in2:   P2 is an input */
#define OPFLG_IN3         0x08  /* in3:   P3 is an input */
#define OPFLG_OUT2        0x10  /* out2:  P2 is an output */
#define OPFLG_OUT3        0x20  /* out3:  P3 is an output */
#define OPFLG_INITIALIZER {\
/*   0 */ 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x10,\
/*   8 */ 0x00, 0x01, 0x00, 0x01, 0x01, 0x01, 0x03, 0x03,\
/*  16 */ 0x01, 0x01, 0x03, 0x12, 0x03, 0x03, 0x01, 0x09,\
/*  24 */ 0x09, 0x09, 0x09, 0x01, 0x09, 0x09, 0x09, 0x09,\
/*  32 */ 0x09, 0x09, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,\
/*  40 */ 0x01, 0x01, 0x01, 0x26, 0x26, 0x23, 0x0b, 0x01,\
/*  48 */ 0x01, 0x03, 0x03, 0x03, 0x0b, 0x0b, 0x0b, 0x0b,\
/*  56 */ 0x0b, 0x0b, 0x01, 0x03, 0x03, 0x01, 0x01, 0x01,\
/*  64 */ 0x01, 0x00, 0x00, 0x02, 0x02, 0x08, 0x00, 0x10,\
/*  72 */ 0x10, 0x10, 0x10, 0x00, 0x10, 0x10, 0x00, 0x00,\
/*  80 */ 0x10, 0x10, 0x00, 0x00, 0x00, 0x02, 0x02, 0x02,\
/*  88 */ 0x00, 0x00, 0x12, 0x1e, 0x20, 0x00, 0x00, 0x00,\
/*  96 */ 0x00, 0x10, 0x10, 0x00, 0x00, 0x00, 0x26, 0x26,\
/* 104 */ 0x26, 0x26, 0x26, 0x26, 0x26, 0x26, 0x26, 0x26,\
/* 112 */ 0x00, 0x00, 0x12, 0x00, 0x00, 0x10, 0x00, 0x00,\
/* 120 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x00,\
/* 128 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00,\
/* 136 */ 0x00, 0x04, 0x04, 0x00, 0x00, 0x10, 0x00, 0x10,\
/* 144 */ 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00,\
/* 152 */ 0x00, 0x10, 0x00, 0x06, 0x10, 0x00, 0x04, 0x1a,\
/* 160 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,\
/* 168 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00,\
/* 176 */ 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,\
/* 184 */ 0x00,}

/* The resolve3P2Values() routine is able to run faster if it knows
** the value of the largest JUMP opcode.  The smaller the maximum
** JUMP opcode the better, so the mkopcodeh.tcl script that
** generated this include file strives to group all JUMP opcodes
** together near the beginning of the list.
*/
#define SQLITE_MX_JUMP_OPCODE  64  /* Maximum JUMP opcode */
