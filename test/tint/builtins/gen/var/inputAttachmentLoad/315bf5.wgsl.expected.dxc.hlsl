SKIP: FAILED


enable chromium_internal_input_attachments;

@group(0) @binding(0) var<storage, read_write> prevent_dce : vec4<i32>;

@input_attachment_index(3) @group(1) @binding(0) var arg_0 : input_attachment<i32>;

fn inputAttachmentLoad_315bf5() -> vec4<i32> {
  var res : vec4<i32> = inputAttachmentLoad(arg_0);
  return res;
}

@fragment
fn fragment_main() {
  prevent_dce = inputAttachmentLoad_315bf5();
}

Failed to generate: <dawn>/test/tint/builtins/gen/var/inputAttachmentLoad/315bf5.wgsl:38:8 error: HLSL backend does not support extension 'chromium_internal_input_attachments'
enable chromium_internal_input_attachments;
       ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


tint executable returned error: exit status 1
