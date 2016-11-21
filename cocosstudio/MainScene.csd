<GameFile>
  <PropertyGroup Name="MainScene" Type="Scene" ID="a2ee0952-26b5-49ae-8bf9-4f1d6279b798" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="Scene" ctype="GameNodeObjectData">
        <Size X="720.0000" Y="1280.0000" />
        <Children>
          <AbstractNodeData Name="spr_background" ActionTag="1234189405" Tag="7" IconVisible="False" LeftMargin="310.0000" RightMargin="310.0000" TopMargin="590.0000" BottomMargin="590.0000" ctype="SpriteObjectData">
            <Size X="100.0000" Y="100.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="360.0000" Y="640.0000" />
            <Scale ScaleX="7.2000" ScaleY="12.8000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="0.1389" Y="0.0781" />
            <FileData Type="Normal" Path="white_rect.png" Plist="" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="Label_time" ActionTag="1285622302" Tag="9" IconVisible="False" BottomMargin="1225.0000" IsCustomSize="True" FontSize="48" LabelText="0" HorizontalAlignmentType="HT_Center" VerticalAlignmentType="VT_Center" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
            <Size X="720.0000" Y="55.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="1.0000" />
            <Position X="360.0000" Y="1280.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="0" G="0" B="0" />
            <PrePosition X="0.5000" Y="1.0000" />
            <PreSize X="1.0000" Y="0.0430" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="spr_target" ActionTag="953446860" Tag="5" IconVisible="False" LeftMargin="310.0000" RightMargin="310.0000" TopMargin="590.0000" BottomMargin="590.0000" ctype="SpriteObjectData">
            <Size X="100.0000" Y="100.0000" />
            <Children>
              <AbstractNodeData Name="spr_target_inner" ActionTag="-632063890" Tag="8" IconVisible="False" ctype="SpriteObjectData">
                <Size X="100.0000" Y="100.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="50.0000" Y="50.0000" />
                <Scale ScaleX="0.9000" ScaleY="0.9000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.5000" />
                <PreSize X="1.0000" Y="1.0000" />
                <FileData Type="Normal" Path="white_circle.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="Label_timeLimit" ActionTag="-1631197422" Tag="10" IconVisible="False" LeftMargin="29.5000" RightMargin="29.5000" TopMargin="9.5000" BottomMargin="9.5000" IsCustomSize="True" FontSize="72" LabelText="" HorizontalAlignmentType="HT_Center" VerticalAlignmentType="VT_Center" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="41.0000" Y="81.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="50.0000" Y="50.0000" />
                <Scale ScaleX="0.5000" ScaleY="0.5000" />
                <CColor A="255" R="0" G="0" B="0" />
                <PrePosition X="0.5000" Y="0.5000" />
                <PreSize X="0.4100" Y="0.8100" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="360.0000" Y="640.0000" />
            <Scale ScaleX="2.0000" ScaleY="2.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="0.1389" Y="0.0781" />
            <FileData Type="Normal" Path="black_circle.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="btn_retry" ActionTag="-1375801767" Tag="7" IconVisible="False" LeftMargin="260.0000" RightMargin="260.0000" TopMargin="1130.0000" BottomMargin="50.0000" TouchEnable="True" FontSize="72" ButtonText="Retry" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="70" Scale9Height="78" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="200.0000" Y="100.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="360.0000" Y="100.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.0781" />
            <PreSize X="0.2778" Y="0.0781" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Normal" Path="white_rect.png" Plist="" />
            <PressedFileData Type="Normal" Path="white_rect.png" Plist="" />
            <NormalFileData Type="Normal" Path="white_rect.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>